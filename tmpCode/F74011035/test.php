<?php
$compressed   = gzcompress('Compress me');
$uncompressed = gzuncompress($compressed);
echo $uncompressed;
?>
