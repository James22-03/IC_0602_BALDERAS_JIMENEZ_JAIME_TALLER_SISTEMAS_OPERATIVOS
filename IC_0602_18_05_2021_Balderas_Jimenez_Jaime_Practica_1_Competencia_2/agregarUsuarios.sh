#!/bin/bash
ROOT_UID=0
SUCCESS=0

# Run as root, of course. (this might not be necessary, because we have to run the script somehow with root anyway)
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi  

file=$1

if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo del listado con nombres de usuario a ingresar..."
   exit 1
fi

# Del archivo con el listado de usuarios a ingresar:
# Este es el formato:
# ejemplo0:x:1001:1001:BO-P.ABIERTAS JAIME BALDERAS 0:/home/ejemplo0:/bin/bash
#    |     |   |    |			|		    |	         |
#    f1    f2  f3   f4                  f5                  f6           f7
#$f1 = username
#$f2 = password
#$f3 = userID
#$f4 = groupID
#$f5 = userID INFO
#$f6 = home directory
#$f1 = comand shell

crearUsuario(){
	eval username="$1"
	eval password="$2"
	eval userID="$3"
	eval groupID="$4"
	eval userINFO="$5"
	eval home="$6"
	eval shell="$7"
	useradd "${username}" -g "${groupID}"
	if [ $? -eq $SUCCESS ];
	then
		echo "Usuario [${username}] agregado correctamente..."
	else
		echo "EL usuario [${username}] no se pudo agregar..."
	fi
}

while IFS=: read -r f1 f2 f3 f4 f5 f6 f7
do
	crearUsuario "\${f1}" "\${f2}" "\${f3}" "\${f4}" "\${f5}" "\${f6}" "\${f7}"	
done < ${file}

exit 0
