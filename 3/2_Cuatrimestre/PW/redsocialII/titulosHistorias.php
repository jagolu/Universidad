<!doctype html>
	<head>
		<META charset="UTF-8">
	</head>
	<body>
		<?php
			$conexion = mysqli_connect("localhost", "*********", "*********");
			mysqli_select_db($conexion, "*********");
			$tildes=$conexion->query("SET NAMES 'utf8'");
			$user=$_GET["user"];
			$result=mysqli_query($conexion, "select titulo, id from entradas where usuario='".$user."'");
			while($extraido=mysqli_fetch_array($result)){
				echo '
						<p>'.$extraido["titulo"].'</p>
				';
			}
		?>
	</body>
</html>
			