package farmacia.farmacia.Cliente;

import android.location.Location;

import java.util.ArrayList;

public class Usuario {
    private String email;
    private String nombreUsuario;
    private String DNI;
    private Carrito carrito;
    private Factura facturaPendiente = null;

    private Location location;

    public Usuario(String email, String nombre_completo, String dni) {
        this.email = email;
        this.nombreUsuario = nombre_completo;
        this.DNI = dni;
        carrito = Carrito.getInstance();
    }

    public void setLocation(double lat, double lon) {
        location = new Location(new String());
        location.setLatitude(lat);
        location.setLongitude(lon);
    }

    public Location getLocation() {
        return location;
    }

    public String getEmail() {
        return email;
    }

    public String getNombre() {
        return nombreUsuario;
    }

    public String getDNI() {
        return DNI;
    }

    public ArrayList<Integer> carritoCompra() {
        ArrayList<Integer> compra = new ArrayList();

        if (carrito.size() > 0) {
            facturaPendiente = carrito.buy();

            if (compra.size() == 0) {
                vaciarCarrito();
            }
        }

        return compra;
    }

    public int totalCarrito() {
        return carrito.size();
    }

    public Factura getFactura() {
        Factura f = facturaPendiente;
        facturaPendiente = null;
        return f;
    }

    public void vaciarCarrito() {
        carrito.clear();
        carrito = Carrito.getInstance();
    }

    void selectFarmacia(String nombre) {
        carrito.setFarmacia(nombre);
    }


    public void aniadirAlCarrito(Producto pro, int cantidad) {
        carrito.add(pro, cantidad);
    }

    public Carrito getCarrito() {
        return carrito;
    }
}
