<?php
ini_set('display_errors', 1);
error_reporting(~0);
$passwd = htmlspecialchars($_POST['passwd']);
$user = htmlspecialchars($_POST['user']);
echo $user;
if ( $link = imap_open("{mail.ncku.edu.tw:143/novalidate-cert}",$user,$passwd) )
{
	imap_close($link);//Close the connection
	echo "Success";
}//End of if{}
else{
	imap_close($link);//Close the connection
$Access_Response = "登入錯誤";
echo $Access_Response;


}//End of else{}
?>
