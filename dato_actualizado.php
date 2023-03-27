<?php

    include 'conexion.php';

    header('Content-Type: text/javascript');

    if($con){

        $query = "select * from datos order by id desc limit 1;";
        $res = $con->query($query);
    }

    while($fila = $res->fetch_array()){
        $dato = $fila["ID"];
    }

    echo $dato;

    $con->close();

?>
