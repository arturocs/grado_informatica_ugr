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

public class Registro extends Activity implements View.OnClickListener{

    private TextView nombre;
    private Button registro;
    private TextView email;
    private TextView passwd1;
    private TextView passwd2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.registro);

        email = (TextView)findViewById(R.id.email_registro);
        passwd1 = (TextView)findViewById(R.id.passwd1);
        passwd2 = (TextView)findViewById(R.id.passwd2);
        nombre = (TextView)findViewById(R.id.nombre_registro);
        registro = (Button)findViewById(R.id.boton_registro);

        registro.setOnClickListener(this);
        email.setOnClickListener(this);
        passwd1.setOnClickListener(this);
        passwd2.setOnClickListener(this);
        nombre.setOnClickListener(this);
    }


    @Override
    public void onClick (View v) {


        if (v.getId() == R.id.boton_registro) {
            if (passwd2.getText().toString().equals(passwd1.getText().toString())) {
                boolean result = ClienteFachada.getInstance().inicializarUsuario(email.getText().toString(), passwd1.getText().toString(),"", nombre.getText().toString());
                login(result);
            } else {
                Toast.makeText(this, "Las contraseñas son distintas", Toast.LENGTH_LONG).show();
            }
        }

        if (v.getId() == R.id.email_registro) {
            email.setText("");
        }

        if (v.getId() == R.id.nombre_registro) {
            nombre.setText("");
        }

        if (v.getId() == R.id.passwd1) {
            passwd1.setText("");
        }

        if (v.getId() == R.id.passwd2) {
            passwd2.setText("");
        }

    }

    public void login(boolean result){
        if (result){
            Toast.makeText(this, "Correcto", Toast.LENGTH_LONG).show();
            startActivity(new Intent(this, Menu.class));
        } else {
            Toast.makeText(this,"Email registrado", Toast.LENGTH_LONG).show();
        }

    }
}
