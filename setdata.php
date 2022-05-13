<?php
  header('Access-Control-Allow-Origin: *');

        //mysqli_connect(host,username,password,dbname,port,socket);
  $link = mysqli_connect("localhost","root","", "lightdb");
  
  if(mysqli_connect_error()) {
    die("There was an error");
  }

  $value = $_GET['value'];

  $query = "UPDATE lighttable SET value=" . "'". $value . "'";
  if($result = mysqli_query($link, $query)) {  
    echo "success";
  } else {
    echo "Error updating record: " . $link->error;
  }

  $link->close();
?>