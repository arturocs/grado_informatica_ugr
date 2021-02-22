package farmacia.farmacia.Interfaz;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;

import farmacia.farmacia.Cliente.ClienteFachada;
import farmacia.farmacia.Cliente.Datos;
import farmacia.farmacia.R;

public class ProductoArrayAdapter<T> extends ArrayAdapter<T> implements View.OnClickListener {
    private Context context;
    private TextView nombre;
    private TextView id;
    private TextView precio;
    private Button comprar;
    private EditText cantidad;

    public ProductoArrayAdapter(Context context, ArrayList<T> productos) {
        super(context, 0, productos);
        this.context = context;
    }


    @Override
    public View getView(int position, View producto_view, ViewGroup parent) {

        LayoutInflater inflater = (LayoutInflater) getContext().getSystemService(Context.LAYOUT_INFLATER_SERVICE);

        View listItemView = producto_view;

        if (producto_view == null) {
            listItemView = inflater.inflate(R.layout.producto, parent, false);
        }


        nombre = (TextView) listItemView.findViewById(R.id.nombre_producto);
        precio = (TextView) listItemView.findViewById(R.id.precio_producto);
        comprar = listItemView.findViewById(R.id.comprar);
        cantidad = (EditText) listItemView.findViewById(R.id.cantidad_producto);

        comprar.setOnClickListener(this);
        cantidad.setOnClickListener(this);

        T item = (T) getItem(position);

        String itemString = item.toString();
        String itemStringSplit[] = itemString.split(",", 3);
        nombre.setText(itemStringSplit[1]);
        precio.setText(itemStringSplit[2] + "€");

        return listItemView;
    }

    private int setCantidad(int c) {
        if (c < 1)
            c = 1;

        cantidad.setText(String.valueOf(c));
        return c;
    }

    @Override
    public void onClick(View v) {

        if (v.getId() == R.id.comprar) {
            View parent = (View) v.getParent();
            id = (TextView) parent.findViewById(R.id.nombre_producto);
            cantidad = (EditText) parent.findViewById(R.id.cantidad_producto);

            int cantidad = setCantidad(Integer.valueOf(this.cantidad.getText().toString()));
            int id_pro = 1;

            for (int key : Datos.getInstance().getProductos().keySet()) {
                if (Datos.getInstance().getProductos().get(key).getNombre().equals(id.getText())) {
                    id_pro = key;
                }
            }

            ClienteFachada.getInstance().aniadirProducto(id_pro, cantidad);
            Toast.makeText(context, "Añadido al carrito" , Toast.LENGTH_SHORT).show();
        }

        if (v.getId() == R.id.cantidad_producto) {
            View parent = (View) v.getParent();
            cantidad = (EditText) parent.findViewById(R.id.cantidad_producto);
            cantidad.setText("");
        }
    }
}