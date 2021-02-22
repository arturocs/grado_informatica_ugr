package farmacia.farmacia.Interfaz;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.util.ArrayList;

import farmacia.farmacia.R;

public class FarmaciasArrayAdapter<T> extends ArrayAdapter<T> {
    private Context context;
    private TextView nombre;
    private View.OnClickListener listener;

    public FarmaciasArrayAdapter(Context context, ArrayList<T> farmacias) {
        super(context, 0, farmacias);
        this.context = context;
    }


    @Override
    public View getView(int position, View view, ViewGroup parent) {

        LayoutInflater inflater = (LayoutInflater) getContext().getSystemService(Context.LAYOUT_INFLATER_SERVICE);

        View listItemView = view;
        if (view == null) {
            listItemView = inflater.inflate(R.layout.farmacia, parent, false);
        }

        nombre = (TextView) listItemView.findViewById(R.id.nombreFarmacia);
        T item = (T) getItem(position);
        String itemString = item.toString();
        String itemStringSplit[] = itemString.split(",", 3);
        nombre.setText(itemStringSplit[0]);
        listItemView.setOnClickListener(listener);

        return listItemView;
    }

    public void setListener(View.OnClickListener l) {
        listener = l;
    }

}
