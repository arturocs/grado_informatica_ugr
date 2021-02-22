# INSTALACIÓN Y CONFIGURACIÓN DE ZABBIX
##### por: Arturo Cortés Sánchez

Antes de nada las maquinas virtuales deben estar conectadas con el proceso de conexión de la sesión 4 de la primera práctica.

## Ubuntu

### Descarga de zabbix server 3.4

`wget http://repo.zabbix.com/zabbix/3.4/ubuntu/pool/main/z/zabbix-release/zabbix-release_3.4-1+xenial_all.deb`
`dpkg -i zabbix-release_3.4-1+xenial_all.deb`

### Instalación del resto de componentes
```l
sudo apt install zabbix-server-mysql
sudo apt-get install zabbix-frontend-php
```

### Ver configuración
```l
zabbix-get -> apt install zabbix-get
zabbix_get -s 192.168.56.106 -k net.tcp.service[ssh]
```

### Crear base de datos
```l
mysql -uroot -p
create database zabbix character set utf8 collate utf8_bin; 
grant all privileges on zabbix.* to zabbix@localhost 
identified by 'practicas,ISE';
quit;
```

### Importar base de datos

```l
zcat /usr/share/doc/zabbix-server-mysql/create.sql.gz | mysql -u zabbix -p 
zabbix
```

### Configurar base de datos
```l
nano /etc/zabbix/zabbix_server.conf

DBHost=localhost <- descomentar linea
DBName=zabbix <- viene ya
DBUser=zabbix <- viene ya
DBPassword=practicas,ISE <- descomentar y añadir contraseña

```

### Iniciar servicio
```l
service zabbix-server start
update-rc.d zabbix-server enable
```

### Activar apache como frontend web
```l
service apache2 restart
```

### Configurar frontend
```l
sudo nano /etc/apache2/conf-enabled/zabbix.conf
```
Descomentar y cambiar timezone
php_value date.timezone Europe/Riga en php5 y php7

### Instalar agente
```l
sudo apt-get install zabbix-agent
sudo systemctl enable zabbix-agent
```

### Configuración del frontend

- Abrir en firefox http://192.168.56.106/zabbix/setup.php
- Verificar requisitos
- Meter contraseña practicas,ISE (no tocar nada mas)
- Siguiente
- Siguiente

### Introducimos las credenciales

usuario: Admin
contraseña: zabbix

### Habilitamos la monitorización de SSH y HTTP

Accedemos a la pestaña Configuration -> Hosts y habilitamos el host por defecto llamado Zabbix server. Seguidamente en la pestaña de templates buscamos y añadimos los templates de SSH y HTTP

## Centos

### Instalación de zabbix-agent en Centos

`rpm -ivh http://repo.zabbix.com/zabbix/3.4/rhel/7/x86_64/zabbix-release-3.4-2.el7.noarch.rpm`

```l
yum install zabbix-agent
yum install policycoreutils-python
semanage permissive -a zabbix_agent_t
systemctl start zabbix-agent

```

En configuration -> Hosts creamos un nuevo host, lo llamamos Centos y le ponemos su IP, en este caso la 192.168.56.110. Acto seguido lo añadimos al grupo de linux servers. Y en la pestaña de Templates buscamos y añadimos los de HTTP y SSH
