<?php
if ($_SERVER["REQUEST_METHOD"] === "POST") {
    // Check if a file was uploaded
    if (isset($_FILES["apkobsuf"])) {
        $uploadedFile = $_FILES["apkobsuf"];

        // Check for errors during upload
        if ($uploadedFile["error"] === UPLOAD_ERR_OK) {
            $uploadedFilePath = $uploadedFile["tmp_name"];

            // Specify the path to the apkobsufucation.jar tool

            // Specify the output directory for the obfuscated APK
            $outputDirectory = "apkobsuf/{$uploadedFilePath}";

            // Build the command to execute

            $command = "java -jar $obfuscationJarPath p -i $uploadedFilePath -o $outputDirectory";
			
			$command = "jarsigner -verbose -sigalg SHA1withRSA -digestalg SHA1 -keystore keystore.jks -storepass 12345678 $outputDirectory mykey";
		
            // Log the command (for debugging purposes)
            error_log("Command: $command");

            // Execute the command
            exec($command, $output, $returnCode);

            // Log the output (for debugging purposes)
            error_log("Output: " . implode("\n", $output));

            // Check the return code for success or failure
            if ($returnCode === 0) {
                echo "APK obfuscated and signed successfully!";
            } else {
                echo "Failed to obfuscate and sign APK. Error code: $returnCode";
                print_r($output); // Output any error messages
            }
        } else {
            echo "Error uploading file. Error code: " . $uploadedFile["error"];
        }
    } else {
        echo "No file uploaded.";
    }
} else {
    echo "Invalid request method.";
}
?>
