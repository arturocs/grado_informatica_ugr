package farmacia.farmacia.Interfaz;


import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import farmacia.farmacia.R;

import java.util.ArrayList;

public class ProductoCarritoArrayAdapter<T> extends ArrayAdapter<T> {
    private Context context;
    private TextView nombre;
    private TextView precio;
    private TextView cantidad;

    public ProductoCarritoArrayAdapter(Context context, ArrayList<T> productos) {
        super(context, 0, productos);
        this.context = context;
    }


    @Override
    public View getView(int position, View producto_view, ViewGroup parent){

        LayoutInflater inflater = (LayoutInflater)getContext()
                .getSystemService(Context.LAYOUT_INFLATER_SERVICE);

        View listItemView = producto_view;

        if (producto_view == null) {
            listItemView = inflater.inflate(R.layout.carrito_producto, parent, false);
        }

        nombre = (TextView)listItemView.findViewById(R.id.nombre);
        precio = (TextView)listItemView.findViewById(R.id.precio_total);
        cantidad = (TextView)listItemView.findViewById(R.id.cantidad_total);


        T item = (T)getItem(position);

        String itemString = item.toString();;
        String itemStringSplit []=itemString.split(",",4);

        cantidad.setText(itemStringSplit[0]);
        nombre.setText(itemStringSplit[2]);
        float precio_total = Float.valueOf(itemStringSplit[3]) * Integer.valueOf(itemStringSplit[0]);
        precio.setText(precio_total + "€");

        return listItemView;
    }
}
