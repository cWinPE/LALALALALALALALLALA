#!/usr/bin/env bash

# make our output look nice...
kit_name="Sleepmask kit"
MASK_TEXT_SECTION=0
USE_SYSCALLS=0
SYSCALLS_FILE="SYSCALLS_none"

function print_good () {
   echo -e "[${kit_name}] \x1B[01;32m[+]\x1B[0m $1"
}

function print_error () {
   echo -e "[${kit_name}] \x1B[01;31m[-]\x1B[0m $1"
}

function print_warning () {
   echo -e "[${kit_name}] \x1B[01;33m[-]\x1B[0m $1"
}

function print_info () {
   echo -e "[${kit_name}] \x1B[01;34m[*]\x1B[0m $1"
}

#
# Compile Sleep Mask for an X64 object
#
function compile_sleepmask64() {

   # compile our 64-bit object files

   print_info "Compile sleepmask.x64.o"
   ${CCx64}-gcc -m64 -c $options -DUSE_${sleep_method} -DMASK_TEXT_SECTION=${MASK_TEXT_SECTION} -DUSE_SYSCALLS=${USE_SYSCALLS} -D${SYSCALLS_FILE} src${version}/sleepmask.c -Wall -o "${1}/sleepmask.x64.o"

   if [[ ${version} -eq "" ]] ; then
      print_info "Compile sleepmask_tcp.x64.o"
      ${CCx64}-gcc -m64 -c $options src${version}/sleepmask_tcp.c -Wall -o "${1}/sleepmask_tcp.x64.o"

      print_info "Compile sleepmask_smb.x64.o"
      ${CCx64}-gcc -m64 -c $options src${version}/sleepmask_smb.c -Wall -o "${1}/sleepmask_smb.x64.o"
   else
      print_info "Compile sleepmask_pivot.x64.o"
      ${CCx64}-gcc -m64 -c $options src${version}/sleepmask_pivot.c -Wall -o "${1}/sleepmask_pivot.x64.o"
   fi
}

function compile_sleepmask() {

   # compile our 32-bit object files
   print_info "Compile sleepmask.x86.o"
   ${CCx86}-gcc -c $options -DUSE_${sleep_method} -DMASK_TEXT_SECTION=${MASK_TEXT_SECTION} -DUSE_SYSCALLS=${USE_SYSCALLS} -D${SYSCALLS_FILE} src${version}/sleepmask.c -Wall -o "${1}/sleepmask.x86.o"

   if [[ ${version} -eq "" ]] ; then
      print_info "Compile sleepmask_tcp.x86.o"
      ${CCx86}-gcc -c $options src${version}/sleepmask_tcp.c -Wall -o "${1}/sleepmask_tcp.x86.o"

      print_info "Compile sleepmask_smb.x86.o"
      ${CCx86}-gcc -c $options src${version}/sleepmask_smb.c -Wall -o "${1}/sleepmask_smb.x86.o"
   else
      print_info "Compile sleepmask_pivot.x86.o"
      ${CCx86}-gcc -c $options src${version}/sleepmask_pivot.c -Wall -o "${1}/sleepmask_pivot.x86.o"
   fi
}


# compiler flags to pass to all builds. Use this to set optimization level or tweak other fun things.
# -Os         - Optimize for size.
options="-Os"

# change up the compiler if you need to
CCx86="i686-w64-mingw32"
CCx64="x86_64-w64-mingw32"

# check for a cross-compiler
if [ $(command -v ${CCx64}-gcc) ]; then
   print_good "You have a x86_64 mingw--I will recompile the sleepmask beacon object files"
else
   print_error "No cross-compiler detected. Try: apt-get install mingw-w64"
   exit 2
fi


#
# compile the sleep mask object files
#

if [[ $# -ne 5 ]]; then
   print_error "Missing parameters"
   print_error "Usage:"
   print_error "./build.sh <version> <sleep_method> <mask_text> <syscalls> <output directory>"
   print_error " - Version          - The sleepmask version. Valid values [47, 49]"
   print_error "                        version 47 supports Cobalt Strike 4.7 and 4.8"
   print_error "                        version 49 supports Cobalt Strike 4.9 and later"
   print_error " - Sleep Method     - Choose which function to use for sleeping"
   print_error "                        Valid options are: Sleep, WaitForSingleObject"
   print_error " - Mask_text        - true or false to mask the text section of beacon"
   print_error " - Syscalls         - set the system call method"
   print_error "                      Valid values [none embedded indirect indirect_randomized]"
   print_error " - Output Directory - Destination directory to save the output"
   print_error "Example:"
   print_error "./build.sh 49 WaitForSingleObject true indirect /tmp/dist/sleepmask"

   exit 2
fi

# Clean

version="${1}"
sleep_method="${2}"
mask_text_section="${3}"
syscalls="${4}"
dist_directory="${5}"


# check the valid version
if [[ "${version}" -eq "47" ]] ; then
   print_info "Building sleepmask to support Cobalt Strike version 4.7 and 4.8"
elif [[ "${version}" -eq "49" ]] ; then
   print_info "Building sleepmask to support Cobalt Strike version 4.9 and later"
else
   print_error "The Version ${version} is not supported"
   exit 2
fi

# Check if the sleep method is valid.
valid_values="Sleep WaitForSingleObject"
if [[ ! $valid_values =~ (^|[[:space:]])"${sleep_method}"($|[[:space:]]) ]] ; then
   print_error "Invalid Sleep Method value: ${sleep_method}"
   print_error "Valid values are: ${valid_values}"
   exit 2
fi
print_info "Using Sleep Method: ${sleep_method}"

#check if mask text section should be compiled
if [[ ${mask_text_section} == "true" ]] ; then
   print_info "Mask text section: true"
   MASK_TEXT_SECTION=1

   # Check if the syscalls is valid.
   valid_values="none embedded indirect indirect_randomized"
   if [[ ! $valid_values =~ (^|[[:space:]])"${syscalls}"($|[[:space:]]) ]] ; then
      print_error "Invalid system call method: ${syscalls}"
      print_error "Valid values are: ${valid_values}"
      exit 2
   fi
   # Setup variables for the system call method
   if [[ ${syscalls} != "none" ]] ; then
      USE_SYSCALLS=1
      SYSCALLS_FILE="SYSCALLS_${syscalls}"

      # -masm=intel - Added to support system calls.
      options="${options} -masm=intel"
   fi
else
   print_info "Mask text section: false"
   if [[ ${syscalls} != "none" ]] ; then
      print_error "System call method ${syscalls} is not supported when mask text section is set to false"
      exit 2
   fi
fi
print_info "Using system call method: ${syscalls}"

rm -rf "${dist_directory}"
mkdir -p "${dist_directory}"

compile_sleepmask "${dist_directory}"
compile_sleepmask64 "${dist_directory}"

sed 's/KITNAME/sleepmask_kit/' ../../templates/helper_functions.template > "${dist_directory}/sleepmask.cna"
cat ./script_template.cna >> "${dist_directory}/sleepmask.cna"

print_good "The sleepmask beacon object files are saved in '${dist_directory}'"
