package farmacia.farmacia.Interfaz;

import android.app.Activity;
import android.content.Intent;
import android.location.Location;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import farmacia.farmacia.Cliente.ClienteFachada;
import farmacia.farmacia.Cliente.Datos;
import farmacia.farmacia.R;

public class Login extends Activity implements View.OnClickListener {

    private TextView email;
    private TextView passwd;
    private Button registro;
    private Button acceder;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.login);

        email = (TextView) findViewById(R.id.email);
        passwd = (TextView) findViewById(R.id.passwd);
        acceder = (Button) findViewById(R.id.acceder);
        registro = (Button) findViewById(R.id.registro);

        acceder.setOnClickListener(this);
        email.setOnClickListener(this);
        passwd.setOnClickListener(this);
        registro.setOnClickListener(this);
    }


    @Override
    public void onClick(View v) {

        if (v.getId() == R.id.registro) {
            startActivity(new Intent(this, Registro.class));
        }
        if (v.getId() == R.id.acceder) {
            login(true);
        }

        if (v.getId() == R.id.email) {
            email.setText("");
        }

        if (v.getId() == R.id.passwd) {
            passwd.setText("");
        }

    }

    public void login(boolean result) {
        if (result) {
            Toast.makeText(Login.this, "Correcto", Toast.LENGTH_SHORT).show();
            cargarUbicacion();
            startActivity(new Intent(this, Menu.class));
        } else {
            Toast.makeText(Login.this, "Error", Toast.LENGTH_SHORT).show();
        }
    }


    protected void cargarUbicacion() {
        Location location = Datos.getInstance().getLocation4();
        ClienteFachada.getInstance().fijarUbicacion(location.getLatitude(), location.getLongitude());
    }
}
