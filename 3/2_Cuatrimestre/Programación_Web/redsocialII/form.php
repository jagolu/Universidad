<?php

//-----------------CONECTAR A BASE DE DATOS--------------------------

    function conectar(){
        $conexion= mysqli_connect("localhost", "pw_77148079", "Xpw_77148079");
        $conexion = mysqli_connect("localhost", "pw_77148079", "Xpw_77148079");
        mysqli_select_db($conexion, "pw_77148079");
        $tildes=$conexion->query("SET NAMES 'utf8'");
        return $conexion;
    }

//-----------------LOGUEARSE-----------------------------------------

    function logIn(){
        $conexion=conectar();
        $usuario=$_POST["usuarioLogIn"];
        $contrasena=$_POST["contrasenaLogIn"];
        $result=mysqli_query($conexion, "select nombreUsuario, password from usuarios where nombreUsuario='".$usuario."'");
        $extraido=mysqli_fetch_array($result);
        if($contrasena===$extraido['password'] && $usuario===$extraido['nombreUsuario']){
            session_start();
            $_SESSION['usuario']=$usuario;
            $bool=1;
            $sql="UPDATE usuarios SET conectado='".$bool."' WHERE nombreUsuario='".$usuario."'";
            $conexion->query($sql);
            header("Location: portada.php?n=0");
        }
        else{
            if($usuario!==$extraido['usuario']){
                header('Location: index.php?login=1');
            }
            else{
                header('Location: index.php?login=1'); 
            }
        }
    }

//----------------REGISTRAR USUARIO----------------------------------

    function registro(){
        $conexion=conectar();
        $usuario=$_POST["usuarioRegistro"];
        $nombre=$_POST["nombreRegistro"];
        $apellidos=$_POST["apellidosRegistro"];
        $contrasena=$_POST["contrasena1Registro"];
        $fecha=$_POST["fechaRegistro"];
        $genero=$_POST["generoRegistro"];
        $null='NULL';
        $bool='0';
        $bool2='0';
        $biografia='Hey there! Im using FindWork';
        $sql="INSERT INTO usuarios VALUES ('".$usuario."', '".$nombre."', '".$apellidos."', '".$fecha."', '".$genero."', '".$contrasena."','".$null."', '".$bool."', '".$biografia."', '".$bool2."')";
        if ($conexion->query($sql) === TRUE) {
            session_start();
            $_SESSION['usuario']=$usuario;
            header("Location: portada.php?n=0");
        } 
        else{
            header('Location: index.php?registrarse=1');
        }
    }

//-------------SUBIR NUEVA HISTORIA----------------------------------
    function subirHistoria(){
        $conexion=conectar();
        session_start();
        $usuario=$_SESSION['usuario'];
        $titulo=$_POST["tituloSubirHistoria"];
        $entrada=$_POST["entradaSubirHistoria"];
        $anio=date("Y");
        $mes=date("m");
        $dia=date("d");
        $hora=date("H");
        $min=date("h");
        $seg=date("s");
        $fecha="".$anio."-".$mes."-".$dia."";
        $hora="".$hora.":".$min.":".$seg."";
        if(!empty($_FILES['imagenSubirHistoria']['name'])){
            $img=$_FILES['imagenSubirHistoria']['tmp_name'];
            $size = getimagesize($img);
            $width = 426;
            $height = 256;
            $src = imagecreatefromstring(file_get_contents($img));
            $dst = imagecreatetruecolor($width,$height);
            imagecopyresampled($dst,$src,0,0,0,0,$width,$height,$size[0],$size[1]);
            imagedestroy($src);
            imagejpeg($dst,$img); 
            imagedestroy($dst);
            $imagen=addslashes(file_get_contents($img));
            $hayImagen='1';
            $sql="INSERT INTO entradas(fecha, hora, usuario, titulo, texto, imagenEntrada, hayImagenEntrada) VALUES ('".$fecha."', '".$hora."', '".$usuario."', '".$titulo."', '".$entrada."', '".$imagen."', '".$hayImagen."')";
        }
        else{
            $imagen="NULL";
            $hayImagen='0';
            $sql="INSERT INTO entradas(fecha, hora, usuario, titulo, texto, imagenEntrada, hayImagenEntrada) VALUES ('".$fecha."', '".$hora."', '".$usuario."', '".$titulo."', '".$entrada."', '".$imagen."', '".$hayImagen."')";
        }
        $conexion->query($sql);
        header('Location: myprofile.php?n=0');
    }
//------------CAMBIAR BIOGRAFIA-----------------------------------------
    function cambiarBiografia(){
        $conexion=conectar();
        session_start();
        $usuario=$_SESSION['usuario'];
        $biografia=$_POST['cambiarBiografia'];
        $sql="UPDATE usuarios SET biografia='".$biografia."' WHERE nombreUsuario='".$usuario."'";
        $conexion->query($sql);
        header('Location: myBiografia.php');
    }
//---------CAMBIAR INFORMACION
    function cambiarInformacion(){
        $conexion=conectar();
        session_start();
        $usuario=$_SESSION['usuario'];
        $nombre=$_POST['changeNombre'];
        $apellidos=$_POST['changeApellidos'];
        $fecha=$_POST['changeFecha'];
        $genero=$_POST['changeGenero'];
        $password=$_POST['changeContrasena'];

        $sql="UPDATE usuarios SET nombre='".$nombre."', apellidos='".$apellidos."', fechaNacimiento='".$fecha."', genero='".$genero."', password='".$password."' WHERE nombreUsuario='".$usuario."'";
        $conexion->query($sql);
        header('Location: myInformacion.php');
    }
//------------CAMBIAR FOTO------------------
    function cambiarFoto(){
        $conexion=conectar();
        session_start();
        $usuario=$_SESSION['usuario'];
        $bool='1';
        $img=$_FILES['changeImagen']['tmp_name'];
        $size = getimagesize($img);
        $width = 207;
        $height = 207;
        $src = imagecreatefromstring(file_get_contents($img));
        $dst = imagecreatetruecolor($width,$height);
        imagecopyresampled($dst,$src,0,0,0,0,$width,$height,$size[0],$size[1]);
        imagedestroy($src);
        imagejpeg($dst,$img); 
        imagedestroy($dst);
        $imagen=addslashes(file_get_contents($img));
        $sql="UPDATE usuarios SET imagen='".$imagen."', hayImagen='".$bool."' WHERE nombreUsuario='".$usuario."'";
        $conexion->query($sql);
        header('Location: myInformacion.php');
    }
//------------------SUBIR COMENTARIO-----------------------
    function subirComentario(){
        $conexion=conectar();
        session_start();
        $usuario=$_SESSION['usuario'];
        $id=$_GET['id'];
        $id2=$_GET['id2'];
        $texto=$_POST['escribirComentario'];
        $anio=date("Y");
        $mes=date("m");
        $dia=date("d");
        $hora=date("H");
        $min=date("h");
        $seg=date("s");
        $fecha="".$anio."-".$mes."-".$dia."";
        $hora="".$hora.":".$min.":".$seg."";
        $sql="INSERT INTO comentarios VALUES ('".$fecha."', '".$hora."', '".$usuario."', '".$texto."', '".$id."', '".$id2."')";
        $conexion->query($sql);
        header('Location: entrada.php?id='.$id.'');
    }
    if(isset($_POST["usuarioLogIn"]) && isset($_POST["contrasenaLogIn"])){
        logIn();
    }
    elseif(isset($_POST['usuarioRegistro']) && isset($_POST['nombreRegistro']) && isset($_POST['apellidosRegistro']) && isset($_POST['contrasena1Registro']) && isset($_POST['fechaRegistro']) && isset($_POST['generoRegistro'])){
        registro();
    }
    else if(isset($_GET['logout'])){
        session_start();
        $conexion=conectar();
        $bool=0;
        $usuario=$_SESSION['usuario'];
        $sql="UPDATE usuarios SET conectado='".$bool."' WHERE nombreUsuario='".$usuario."'";
        $conexion->query($sql);
        session_destroy();
        header('Location: index.php');
    }
    else if(isset($_POST["tituloSubirHistoria"]) && isset($_POST["entradaSubirHistoria"])){
       subirHistoria();
    }
    else if(isset($_POST['cambiarBiografia'])){
        cambiarBiografia();
    }
    else if(isset($_POST['changeNombre']) && isset($_POST['changeApellidos']) && isset($_POST['changeGenero'])){
        cambiarInformacion();
    }
    else if(isset($_POST['actualizarImagen'])){
        cambiarFoto();
    }
    else if(isset($_POST['escribirComentario'])){
        subirComentario();
    }
    else{
        echo "mal";
    }
?>