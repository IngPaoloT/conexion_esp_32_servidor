<?php

include 'conexion.php';

if($con){
	echo "Conexión con base de datos exitosa...";
	
	if(isset($_POST['tem'])){
		
		$tem = $_POST['tem'];
		echo "Temperatura: ".$tem;
	}
		
	if(isset($_POST['hum'])){
		$hum = $_POST['hum'];
		echo "Humedad: ".$hum;
		
		$consulta = "INSERT INTO datos(tem,hum) VALUES ('$tem','$hum')";
		$resultado = mysqli_query($con,$consulta);
		
		if($resultado){
			echo "Registro en base de datos OK";
		}
		else{
			echo "Falla en registro BD.";
		}
	}
}

?>
