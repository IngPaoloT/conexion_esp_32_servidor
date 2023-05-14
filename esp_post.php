<?php

include 'conexion.php';

if($con){
	echo "Conexión con base de datos exitosa...";
	
	if(isset($_POST['variable1'])){
		
		$tem = $_POST['variable1'];
		echo "Temperatura: ".$tem;
	}
		
	if(isset($_POST['variable2'])){
		$hum = $_POST['variable2'];
		echo "Humedad: ".$hum;
		
		$consulta = "Query de consulta a la base de datos";
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
