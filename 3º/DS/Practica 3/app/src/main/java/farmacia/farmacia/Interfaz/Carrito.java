package farmacia.farmacia.Interfaz;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;

import farmacia.farmacia.Cliente.ClienteFachada;
import farmacia.farmacia.Cliente.ElementoCarrito;
import farmacia.farmacia.Cliente.ProductoGenerico;
import farmacia.farmacia.R;

public class Carrito extends Activity implements View.OnClickListener {

    private Button comprarButton;
    private Button vaciarButton;
    private ListView listaCompra;
    private ArrayAdapter arrayAdapter;

    private void inicializarCarrito() {
        ArrayList<ElementoCarrito> carrito_lineas = ClienteFachada.getInstance().getCarrito();

        arrayAdapter = new ProductoCarritoArrayAdapter(this, carrito_lineas);
        listaCompra.setAdapter(arrayAdapter);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.carrito);

        comprarButton = (Button) findViewById(R.id.comprarButton);
        vaciarButton = (Button) findViewById(R.id.vaciarButton);
        listaCompra = (ListView) findViewById(R.id.listaCompra);

        comprarButton.setOnClickListener(this);
        vaciarButton.setOnClickListener(this);

        inicializarCarrito();
    }

    @Override
    public void onClick(View v) {
        if (v.getId() == R.id.comprarButton) {
            boolean correcto = ClienteFachada.getInstance().getUsuario().totalCarrito() > 0;
            if (!correcto) {
                Toast.makeText(this, "Error", Toast.LENGTH_SHORT).show();
            } else {
                ArrayList<Integer> compra = ClienteFachada.getInstance().comprar();

                if (compra.size() != 0) {
                    ArrayList<ProductoGenerico> productos_compra = null;
                    String itemString = "";

                    if (productos_compra.size() > 0)
                        itemString = productos_compra.get(0).getNombre();

                    for (int i = 1; i < productos_compra.size() - 1; i++) {
                        itemString += ", " + productos_compra.get(i).getNombre();
                    }

                    Toast.makeText(this, "Error" + itemString, Toast.LENGTH_SHORT).show();
                }

                startActivity(new Intent(this, Compra.class));
            }
        }

        if (v.getId() == R.id.vaciarButton) {
            ClienteFachada.getInstance().getUsuario().vaciarCarrito();
            inicializarCarrito();
        }
    }


}
