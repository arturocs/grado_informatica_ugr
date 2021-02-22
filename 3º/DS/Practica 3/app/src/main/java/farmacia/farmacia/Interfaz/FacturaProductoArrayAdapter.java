package farmacia.farmacia.Interfaz;


import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.util.ArrayList;

import farmacia.farmacia.R;

public class FacturaProductoArrayAdapter<T> extends ArrayAdapter<T> {
    private Context context;
    private TextView nombre;
    private TextView cantidad;
    private TextView precio;

    public FacturaProductoArrayAdapter(Context context, ArrayList<T> lineas) {
        super(context, 0, lineas);
        this.context = context;
    }

    @Override
    public View getView(int position, View producto_view, ViewGroup parent) {

        LayoutInflater inflater = (LayoutInflater) getContext()
                .getSystemService(Context.LAYOUT_INFLATER_SERVICE);

        View listItemView = producto_view;

        if (producto_view == null) {
            listItemView = inflater.inflate(R.layout.factura_producto, parent, false);
        }

        nombre = (TextView) listItemView.findViewById(R.id.name);
        cantidad = (TextView) listItemView.findViewById(R.id.cantidad);
        precio = (TextView) listItemView.findViewById(R.id.precio);

        T item = (T) getItem(position);

        String itemString = item.toString();
        String itemStringSplit[] = itemString.split(",", 3);

        nombre.setText(itemStringSplit[0]);
        cantidad.setText(itemStringSplit[1]);
        precio.setText(itemStringSplit[2] + "€");

        return listItemView;
    }
}