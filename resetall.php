<?php
  // This one is working 
  // The client is Phonegap app:  PHP API Client
  header('Access-Control-Allow-Origin: *');

        //mysqli_connect(host,username,password,dbname,port,socket);
  $link = mysqli_connect("localhost/3325","root","", "lightdb");
  
  if(mysqli_connect_error()) {
    die("There was an error");
  }

  $query = "UPDATE lighttable SET value='0'";

  if($result = mysqli_query($link, $query)) {  
    echo "success";
  } else {
    echo "Error updating record: " . $link->error;
  }

  $link->close();
?>