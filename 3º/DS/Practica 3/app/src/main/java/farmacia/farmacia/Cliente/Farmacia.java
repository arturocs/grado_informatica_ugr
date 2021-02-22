package farmacia.farmacia.Cliente;

import android.location.Location;

import java.util.ArrayList;
import java.util.HashMap;

public class Farmacia {
    public HashMap<Integer, Producto> productos_farmacia;
    private String nombre;
    private Location location;


    public Farmacia(String nombre, Location localizacion) {
        this.nombre = nombre;
        this.productos_farmacia = Datos.getInstance().getProductos();
        this.location = localizacion;
    }

    public String getNombre() {
        return nombre;
    }

    public Location getLocation() {
        return location;
    }

    @Override
    public String toString() {
        return getNombre() + "," + getLocation();
    }

    public ArrayList<Producto> getProductosFarmacia() {
        ArrayList<Producto> productos = new ArrayList();
        for (Producto producto_farmacia : productos_farmacia.values())
            productos.add(producto_farmacia);
        return productos;
    }
}
