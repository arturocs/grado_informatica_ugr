package farmacia.farmacia.Interfaz;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;

import farmacia.farmacia.Cliente.ClienteFachada;
import farmacia.farmacia.Cliente.Farmacia;
import farmacia.farmacia.R;


public class Farmacias extends Activity implements View.OnClickListener {

    private ListView lista;
    private ArrayAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.farmacias);

        lista = (ListView) findViewById(R.id.listViewFarmacias);
        ArrayList<Farmacia> farmacias = ClienteFachada.getInstance().getFarmaciasCercanas();
        adapter = new FarmaciasArrayAdapter(this, farmacias);

        ((FarmaciasArrayAdapter) adapter).setListener(this);
        lista.setAdapter(adapter);
    }


    @Override
    public void onClick(View v) {
        TextView nombre_tv = (TextView) v.findViewById(R.id.nombreFarmacia);
        String farmacia = nombre_tv.getText().toString();
        ClienteFachada.getInstance().setFarmacia(farmacia);
        startActivity(new Intent(this, ListaProductos.class));
    }

}
