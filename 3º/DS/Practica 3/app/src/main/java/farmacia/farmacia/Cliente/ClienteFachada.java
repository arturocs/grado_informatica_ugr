package farmacia.farmacia.Cliente;

import android.location.Location;

import java.util.ArrayList;


public class ClienteFachada {
    private static ClienteFachada INSTANCE = new ClienteFachada();
    private Datos datos = Datos.getInstance();
    private Usuario usuario = datos.getUsuario();
    private boolean identificado = false;
    private String farmacia = null;

    private ClienteFachada() {}

    public static ClienteFachada getInstance() {
        return INSTANCE;
    }

    public boolean inicializarUsuario(String email, String pass, String dni, String nombre) {
        identificado = (usuario != null);
        return identificado;
    }

    public void logout() {
        usuario = null;
        identificado = false;
    }

    public void fijarUbicacion(double lat, double lon) {
        usuario.setLocation(lat, lon);
    }

    public Usuario getUsuario() {
        return usuario;
    }

    public ArrayList<Integer> comprar() {
        ArrayList<Integer> compra = usuario.carritoCompra();
        return compra;
    }

    public Factura getFactura() {
        return usuario.getFactura();
    }

    public void aniadirProducto(int id, int cantidad) {
        Producto producto = Datos.getInstance().getProductos().get(id);
        getUsuario().aniadirAlCarrito(producto, cantidad);
    }

    public ArrayList<ElementoCarrito> getCarrito() {
        return getUsuario().getCarrito().getListaElementos();
    }

    public void setFarmacia(String nombre) {
        usuario.selectFarmacia(nombre);
        farmacia = nombre;
    }

    public String getFarmacia() {
        return farmacia;
    }

    public ArrayList<Farmacia> getFarmacias() {
        ArrayList<Farmacia> farmacias = Datos.getInstance().getFarmacias();
        return farmacias;
    }

    public ArrayList<Farmacia> getFarmaciasCercanas() {
        ArrayList<Farmacia> farmacias = getFarmacias();
        Float min;
        Farmacia f;
        Location location = usuario.getLocation();

        for (int i = 0; i < farmacias.size(); i++) {
            f = farmacias.get(i);
            Location location1 = farmacias.get(i).getLocation();
            min = location.distanceTo(location1);
            for (int j = i + 1; j < farmacias.size(); j++) {
                location1 = farmacias.get(j).getLocation();
                if (location.distanceTo(location1) < min) {
                    f = farmacias.get(j);
                    min = location.distanceTo(location1);
                }
            }
        }
        return farmacias;
    }

    public ArrayList<Producto> getProductos(String nombre) {
        Farmacia farmacia = Datos.getInstance().getFarmacias().get(0);
        ArrayList<Farmacia> farmacias = Datos.getInstance().getFarmacias();
        for (Farmacia f : farmacias) {
            if (nombre.equals(f.getNombre())) {
                farmacia = f;
            }
        }
        ArrayList<Producto> productos = farmacia.getProductosFarmacia();
        return productos;
    }
}
