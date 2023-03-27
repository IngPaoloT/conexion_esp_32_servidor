<?php

    include 'conexion.php';

    header('Content-Type: text/javascript');

    if($con){

        $query = "select * from datos order by id desc limit 1;";
        $res = $con->query($query);
    }

    while($fila = $res->fetch_array()){
        $tem = $fila["tem"];
        $hum = $fila["hum"];
    }
    
    if($_GET["valor"]=="temp"){
        echo $tem;
    }
    
    else{
        echo $hum;  
    }

    $con->close();

?>
