function comprobarLogIn(){
	var a=1;
	camposTexto=document.getElementById("formularioLogIn").elements;
	if(camposTexto[0].value=='' && camposTexto[0].type=='text'){
		alert("El campo del nombre de usuario esta vacio y es OBLIGATORIO");
		a=0;
	}
	if(camposTexto[1].value=='' && camposTexto[1].type=='password'){
		alert("El campo de la contraseña esta vacio y es OBLIGATORIO");
		a=0;
	}
	if(a==0){
		return false;
	}
}

function comprobarRegistro(){
	var a=1;
	camposTexto=document.getElementById("formularioRegistro").elements;
	if(camposTexto[0].value==''){
		alert("El campo del nombre de usuario esta vacio y es OBLIGATORIO");
		a=0;
	}
	else if(camposTexto[0].value.length>9){
		alert("El campo del nombre de usuario tiene como máximo 9 caracteres");
		a=0;
	}
	if(camposTexto[1].value==''){
		alert("El campo del nombre esta vacio y es OBLIGATORIO");
		a=0;
	}
	else if(camposTexto[1].value.length>15){
		alert("El campo del nombre tiene como máximo 15 caracteres");
		a=0;
	}
	if(camposTexto[2].value==''){
		alert("El campo de apellidos esta vacio y es OBLIGATORIO");
		a=0;
	}
	else if(camposTexto[2].value.length>32){
		alert("El campo de apellidos tiene como máximo 32 caracteres");
		a=0;
	}
	if(camposTexto[3].value.length==0){
		alert("El campo de contraseña esta vacio y es OBLIGATORIO");
		a=0;
	}
	else if(camposTexto[3].value.length<3){
		alert("El campo de contraseña debe tener un minimo de 3 caracteres");
		a=0;
	}
	else if(camposTexto[3].value.length>10){
		alert("El campo de contraseña debe tener un maximo de 10 caracteres");
		a=0;
	}
	if(camposTexto[4].value.length==0){
		alert("El campo de fecha esta vacio y es OBLIGATORIO");
		a=0;
	}
	if(a==0){
		return false;
	}
}

function comprobarBiografia(){
	campoTexto=document.getElementById("formMyBiografia").elements;
	if(campoTexto[0].value==''){
		alert("El campo de texto esta vacio y es OBLIGATORIO");
		return false;
	}
	if(campoTexto[0].value.length>50){
		alert("Máximo de 50 carácteres");
		return false;
	}
}

function comprobarSubirHistoria(){
	campoTexto=document.getElementById("formSubirHistoria").elements;
	var a=1;
	if(campoTexto[0].value==''){
		alert("El campo de texto de titulo esta vacio y es OBLIGATORIO");
		a=0;
	}
	else if(campoTexto[0].value.length>15){
		alert("El titulo tiene como maximo 15 caracteres");
		a=0;
	}
	if(campoTexto[1].value.length>150){
		alert("Máximo de 150 carácteres en el texto de la entrada");
		a=0;
	}
	else if(campoTexto[1].value.length==''){
		alert("El campo de texto de la entrada esta vacio y es OBLIGATORIO");
		a=0;
	}
	if(a==0){
		return false;
	}
}

function comprobarInformacion(){
	var a=1;
	camposTexto=document.getElementById("formInformacion").elements;
	if(camposTexto[0].value==''){
		alert("El campo del nombre esta vacio y es OBLIGATORIO");
		a=0;
	}
	else if(camposTexto[0].value.length>15){
		alert("El campo del nombre tiene como máximo 15 caracteres");
		a=0;
	}
	if(camposTexto[1].value==''){
		alert("El campo de apellidos esta vacio y es OBLIGATORIO");
		a=0;
	}
	else if(camposTexto[1].value.length>32){
		alert("El campo de apellidos tiene como máximo 32 caracteres");
		a=0;
	}
	if(camposTexto[2].value.length==0){
		alert("El campo de contraseña esta vacio y es OBLIGATORIO");
		a=0;
	}
	else if(camposTexto[2].value.length<3){
		alert("El campo de contraseña debe tener un minimo de 3 caracteres");
		a=0;
	}
	else if(camposTexto[2].value.length>10){
		alert("El campo de contraseña debe tener un maximo de 10 caracteres");
		a=0;
	}
	if(camposTexto[3].value.length==0){
		alert("El campo de fecha esta vacio y es OBLIGATORIO");
		a=0;
	}
	if(a==0){
		return false;
	}
}

function comprobarComentario(){
	camposTexto=document.getElementById("formComentario").elements;
	if(camposTexto[0].value==''){
		alert("El campo de comentario esta vacio y es OBLIGATORIO");
		return false;
	}
	else if(camposTexto[0].value.length>100){
		alert("El campo de comentario tiene como maximo 100 caracteres");
		return false;
	}	
}

function cargarHistorias(usuario){
	window.open("http://bahia.ugr.es/~/redsocialII/titulosHistorias.php?user="+usuario, "Historias de "+usuario, "width=300, height=200");
}

