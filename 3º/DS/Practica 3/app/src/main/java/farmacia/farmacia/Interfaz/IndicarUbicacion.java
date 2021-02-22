package farmacia.farmacia.Interfaz;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import farmacia.farmacia.Cliente.ClienteFachada;
import farmacia.farmacia.R;


public class IndicarUbicacion extends Activity implements View.OnClickListener {

    TextView longitud;
    TextView latitud;
    Button aplicar_button;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.fijar_ubicacion);

        longitud = (TextView) findViewById(R.id.longitud);
        latitud = (TextView) findViewById(R.id.latitud);
        aplicar_button = (Button) findViewById(R.id.aplicar_button);

        longitud.setOnClickListener(this);
        latitud.setOnClickListener(this);
        aplicar_button.setOnClickListener(this);

        longitud.setText(Double.toString(ClienteFachada.getInstance().getUsuario().getLocation().getLongitude()));
        latitud.setText(Double.toString(ClienteFachada.getInstance().getUsuario().getLocation().getLatitude()));

    }

    @Override
    public void onClick(View v) {
        if (v.getId() == R.id.aplicar_button) {
            ClienteFachada.getInstance().fijarUbicacion(Float.valueOf(latitud.getText().toString()), Float.valueOf(longitud.getText().toString()));
            Toast.makeText(this, "Ubiacion fijada", Toast.LENGTH_SHORT).show();
            startActivity(new Intent(this, Menu.class));
        }

        if ((v.getId() == R.id.latitud) || (v.getId() == R.id.longitud)) {
            latitud.setText("");
            longitud.setText("");
        }

    }
}