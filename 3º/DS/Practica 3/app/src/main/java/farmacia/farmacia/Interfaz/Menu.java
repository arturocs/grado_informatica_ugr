package farmacia.farmacia.Interfaz;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import farmacia.farmacia.Cliente.ClienteFachada;
import farmacia.farmacia.R;

public class Menu extends Activity implements View.OnClickListener {

    Button administracion;
    Button catalogo;
    Button carrito;
    Button cerrar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.menu);

        administracion = (Button) findViewById(R.id.administracion);
        catalogo = (Button) findViewById(R.id.catalogo);
        carrito = (Button) findViewById(R.id.carrito);
        cerrar = (Button) findViewById(R.id.cerrar);

        administracion.setOnClickListener(this);
        catalogo.setOnClickListener(this);
        carrito.setOnClickListener(this);
        cerrar.setOnClickListener(this);
    }


    @Override
    public void onClick(View v) {
        if (v.getId() == R.id.administracion) {
            startActivity(new Intent(this, Perfil.class));
        }

        if (v.getId() == R.id.catalogo) {
            startActivity(new Intent(this, Farmacias.class));
        }

        if (v.getId() == R.id.carrito) {
            startActivity(new Intent(this, Carrito.class));
        }

        if (v.getId() == R.id.cerrar) {
            ClienteFachada.getInstance().logout();
            startActivity(new Intent(this, Login.class));
        }
    }
}