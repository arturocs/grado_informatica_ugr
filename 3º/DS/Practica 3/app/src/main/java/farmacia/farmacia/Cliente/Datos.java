package farmacia.farmacia.Cliente;

import android.location.Location;

import java.util.ArrayList;
import java.util.HashMap;

public class Datos {
    private static final Datos INSTANCE = new Datos();
    private Usuario usuario;
    private ArrayList<Farmacia> farmacias;
    private HashMap<Integer, Producto> productos;
    private Location location1;
    private Location location2;
    private Location location3;
    private Location location4;

    private Datos() {
        this.usuario = new Usuario("usuario@usuario.com", "Usuario", "2345678K");
        this.usuario.setLocation(37.134658, -3.669388);
        this.farmacias = new ArrayList();
        this.productos = new HashMap<Integer, Producto>();
        productos.put(1, new Producto(1, "Paracetamol", 2.5));
        productos.put(2, new Producto(2, "Aspirina", 5.0));
        productos.put(3, new Producto(3, "Ibuprofeno", 2.0));

        location1 = new Location(new String());
        location2 = new Location(new String());
        location3 = new Location(new String());
        location4 = new Location(new String());

        location1.setLatitude(37.135458);
        location1.setLongitude(-3.668615);

        location2.setLatitude(37.136230);
        location2.setLongitude(-3.668839);

        location3.setLatitude(37.133306);
        location3.setLongitude(-3.670842);

        location4.setLongitude(37.136240);
        location4.setLatitude(-3.670852);
    }

    public static Datos getInstance() {
        return INSTANCE;
    }

    public ArrayList<Farmacia> getFarmacias() {
        Farmacia farmacia = new Farmacia("FARMACIA FUENTES RUIZ-CHENA, C.B.", location1);
        farmacias.add(farmacia);
        farmacia = new Farmacia("FARMACIA FUENTES RUIZ-CHENA, C.B.", location2);
        farmacias.add(farmacia);
        farmacia = new Farmacia("FARMACIA Dr. Manuel Larrubia Cara", location3);
        farmacias.add(farmacia);

        return farmacias;
    }

    public Location getLocation4() {
        return location4;
    }

    public Usuario getUsuario() {
        return usuario;
    }

    public HashMap<Integer, Producto> getProductos() {

        return productos;
    }
}
