<?php
echo '<!DOCTYPE HTML PUBLIC "-IETFDTD HTML 2.0EN">'.PHP_EOL;
echo '<html><head>'.PHP_EOL;
echo '<title>404 Not Found</title>'.PHP_EOL;
echo '</head><body>'.PHP_EOL;
echo '<h1>Not Found</h1>'.PHP_EOL;
echo '<p>The requested URL ' . $_SERVER['REQUEST_URI'] . ' was not found on this server.</p>'.PHP_EOL;
echo '<p>Additionally, a 404 Not Found'.PHP_EOL;
echo 'error was encountered while trying to use an ErrorDocument to handle the request.</p>'.PHP_EOL;
echo '</body></html>'.PHP_EOL;
exit();
?>