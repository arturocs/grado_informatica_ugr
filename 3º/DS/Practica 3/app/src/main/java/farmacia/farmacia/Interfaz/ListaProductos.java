package farmacia.farmacia.Interfaz;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;

import java.util.ArrayList;

import farmacia.farmacia.Cliente.ClienteFachada;
import farmacia.farmacia.Cliente.Producto;
import farmacia.farmacia.R;

//import farmacia.farmacia.Cliente.Departamentos;


public class ListaProductos extends Activity implements View.OnClickListener {

    private Button boton;
    private ListView lista;
    private ArrayAdapter adapter;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.lista_productos);
        boton = (Button) findViewById(R.id.volver_lista);
        lista = (ListView) findViewById(R.id.listViewCatalogo);
        String nombre = ClienteFachada.getInstance().getFarmacia();
        ArrayList<Producto> productos = ClienteFachada.getInstance().getProductos(nombre);
        boton.setOnClickListener(this);
        adapter = new ProductoArrayAdapter(this, productos);
        lista.setAdapter(adapter);
    }

    @Override
    public void onClick(View v) {
        if (v.getId() == R.id.volver_lista)
            startActivity(new Intent(this, Menu.class));
    }

}
