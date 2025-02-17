# Cobalt Strike Arsenal Kit

(c) 2012-2023 Fortra, LLC and its group of companies. All trademarks and registered trademarks are the property of their respective owners.

Build script for the Cobalt Strike Arsenal Kit

## Description

The arsenal kit is the combination of the individual kits into a single kit.
Building this kit yields a single aggressor script `dist/arsenal_kit.cna`
that can be loaded instead of loading individual kits. This kit is controlled
by the `arsenal_kit.config` file which configures the kits that are built with
the `build_arsenal_kit.sh` script.

The individual kits can still be used independently. Each kit has its own
aggressor script file located in the `dist/<kit_name>/<kit_name>.cna` which
can individually be loaded.  Refer to the kit readme for details. 

The `build_arsenal_kit.sh` script builds the kits that are enabled in the
`arsenal_kit.config` file, which executes the `kits/<kit_name>/build.sh`
script for each enabled kit.  To build an individual kit change directory
into `kits/<kit_name>` and execute the `build.sh`.  For the individual kit
`build.sh` scripts run with no parameters to see the help text for more
information on the required parameters.

Please note, the `udrl-vs` kit and the `mutator` kit are standalone and must be built separately.
They are not included within the `arsenal_kit.config` file or
`build_arsenal_kit.sh` script.

## Kit and supported Cobalt Strike Versions

Kit                   | Cobalt Strike Version
----------------------|----------------------
Artifact              | 4.x 
Sleepmask             | 4.7 and higher
UDRL                  | 4.4 and higher
UDRL-VS               | 4.4 and higher
Mimikatz (20220919)   | 4.5 and higher
Resource              | 4.x
Process Inject        | 4.5 and higher
Mutator               | 4.7 and higher

- Not included
  - Elevate Kit
  - applet
  - powerapplet

The sleepmask kit for version 4.4 is available for download at https://download.cobaltstrike.com/scripts   
The sleepmask kit for version 4.5 and 4.6 are available in arsenal kits 20230911 and earlier

## Kit File and Directory Descriptions

Location                             | Description
-------------------------------------|------------
arsenal_kit.config                   | Arsenal kit config
build_arsenal_kit.sh                 | Arsenal kit build script
templates/                           | Aggressor script global templates
templates/arsenal_kit.cna.template   | Arsenal kit template base script
templates/helper_functions.template  | Helper functions template script
dist/                                | The default location for the build output
kits/                                | Source for the kits
kits/< KIT >/script_template.cna     | Base template for the kit

## Requirements

This kit was designed to be run on a Linux platform. It has been tested on Debian based Linux.

You will need the following:

- Minimal GNU for Windows Cross-Compiler - `apt-get install mingw-w64`

## Quick Start

1) Review and edit `arsenal_kit.config` to set included kits to true
2) Build the kits `build_arsenal_kit.sh`
3) Load the script - In Cobalt Strike -> Script Manager -> Load `dist/arsenal_kit.cna`

Commands that use the hooks will present output in the script console.

Example of generating an artifact (only the artifact kit enabled):
```
[10:16:12] [arsenal_kit.cna] ######################################
[10:16:12] [arsenal_kit.cna] # Cobalt Strike Arsenal Kit
[10:16:12] [arsenal_kit.cna] # (c) 2012-2023 Fortra, LLC and its group of companies. All trademarks and registered trademarks are the property of their respective owners.
[10:16:12] [arsenal_kit.cna] ######################################
[10:16:12] [arsenal_kit.cna] Artifact Kit Loaded
[10:16:25] [arsenal_kit.cna] Artifact - EXECUTABLE_ARTIFACT_GENERATOR hook
[10:16:25] [arsenal_kit.cna] Artifact - /home/arsenal-kit/dist/artifact/artifact64big.exe
[10:16:25] [arsenal_kit.cna] Artifact - Length 265737
```

# Modifications

You're encouraged to make modifications to this code and use these modifications in your
engagements. Do not redistribute this source code. It is not open source. It is provided as a
benefit to licensed Cobalt Strike users.

Each kit has a readme with details on how to customize.

# License

This code is subject to the end user license agreement for Cobalt Strike. The complete
license agreement is at:

https://www.cobaltstrike.com/license

The readme file in each kit will include any specific license information regarding that specific kit.
