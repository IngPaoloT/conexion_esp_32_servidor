<?php

    include 'conexion.php';

    header('Content-Type: text/javascript');

    if($con){

        $query = "query de consulta de la tabla elegida en la base de datos";
        $res = $con->query($query);
    }

    while($fila = $res->fetch_array()){
        $tem = $fila["variable1"];
        $hum = $fila["variable2"];
    }
    
    if($_GET["valor"]=="variable1"){
        echo $tem;
    }
    
    else{
        echo $hum;  
    }

    $con->close();

?>
