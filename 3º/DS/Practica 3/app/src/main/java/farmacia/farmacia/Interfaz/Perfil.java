package farmacia.farmacia.Interfaz;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import farmacia.farmacia.R;

import farmacia.farmacia.Cliente.ClienteFachada;

public class Perfil extends Activity implements View.OnClickListener{

    TextView nombre;
    TextView passwd;
    Button aceptar_nombre;
    Button aceptar_passwd;
    Button atras;
    Button fijar_ubicacion;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.perfil);

        nombre = (TextView)findViewById(R.id.nombre_usuario);
        passwd = (TextView)findViewById(R.id.passwd_perfil);
        aceptar_nombre = (Button)findViewById(R.id.aceptar_nombre);
        aceptar_passwd = (Button)findViewById(R.id.aceptar_passwd);
        atras = (Button)findViewById(R.id.atras);
        fijar_ubicacion = (Button)findViewById(R.id.fijar_ubicacion);

        nombre.setOnClickListener(this);
        passwd.setOnClickListener(this);
        aceptar_nombre.setOnClickListener(this);
        aceptar_passwd.setOnClickListener(this);
        atras.setOnClickListener(this);
        fijar_ubicacion.setOnClickListener(this);
        nombre.setText(ClienteFachada.getInstance().getUsuario().getNombre());

    }

    @Override
    public void onClick(View v) {
        if (v.getId() == R.id.aceptar_nombre) {
            Toast.makeText(this,"Correcto", Toast.LENGTH_SHORT).show();
        }

        if (v.getId() == R.id.aceptar_passwd) {
            Toast.makeText(this, "Nueva contraseña fijada", Toast.LENGTH_SHORT).show();
        }

        if (v.getId() == R.id.atras) {
            startActivity(new Intent(this, Menu.class));
        }

        if (v.getId() == R.id.fijar_ubicacion) {
            startActivity(new Intent(this, IndicarUbicacion.class));
        }

        if (v.getId() == R.id.passwd_perfil) {
            passwd.setText("");
        }
    }
}
