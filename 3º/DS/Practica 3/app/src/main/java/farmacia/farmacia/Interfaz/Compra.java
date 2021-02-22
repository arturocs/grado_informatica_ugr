package farmacia.farmacia.Interfaz;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;

import farmacia.farmacia.Cliente.ClienteFachada;
import farmacia.farmacia.Cliente.ElementoFactura;
import farmacia.farmacia.Cliente.Factura;
import farmacia.farmacia.R;


public class Compra extends Activity implements View.OnClickListener {

    private ListView listViewFactura;
    private TextView precio_final;
    private Button volver;
    private ArrayAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.compra);
        Factura factura = ClienteFachada.getInstance().getFactura();
        precio_final = (TextView) findViewById(R.id.precio_final);
        listViewFactura = (ListView) findViewById(R.id.listView_actura);
        volver = (Button) findViewById(R.id.volver);
        volver.setOnClickListener(this);
        precio_final.setText(String.valueOf(factura.getTotal()) + "€");
        ArrayList<ElementoFactura> elementos = factura.getListaElementos();
        adapter = new FacturaProductoArrayAdapter(this, elementos);
        listViewFactura.setAdapter(adapter);

    }

    @Override
    public void onClick(View v) {
        if (v.getId() == R.id.volver) {
            startActivity(new Intent(this, Menu.class));
        }
    }

}
