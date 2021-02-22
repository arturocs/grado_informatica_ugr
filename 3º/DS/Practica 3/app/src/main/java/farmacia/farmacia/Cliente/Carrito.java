package farmacia.farmacia.Cliente;

import java.util.ArrayList;
import java.util.HashMap;

public class Carrito {
    private static Carrito INSTANCE = new Carrito();
    private HashMap<Integer, ElementoCarrito> compra;
    private String nombre;

    private Carrito() {
        compra = new HashMap();
    }

    public static Carrito getInstance() {
        return INSTANCE;
    }

    public void clear() {
        INSTANCE = new Carrito();
    }

    public void add(Producto producto, int cantidad) {
        if (!contiene(producto.getId())) {
            compra.put(producto.getId(), new ElementoCarrito(producto, cantidad));
        } else
            compra.get(producto.getId()).aniadir(cantidad);

    }

    public Factura buy() {
        Factura factura = new Factura();

        for (ElementoCarrito linea : compra.values()) {
            factura.aniadirProducto(linea.getProducto(), linea.getCantidad());
        }

        return factura;

    }

    public int size() {
        return compra.size();
    }

    public void setFarmacia(String nombre) {
        this.nombre = nombre;
    }

    public ArrayList<ElementoCarrito> getListaElementos() {
        ArrayList<ElementoCarrito> elementos = new ArrayList();

        for (ElementoCarrito linea : compra.values())
            elementos.add(linea);

        return elementos;
    }

    public boolean contiene(int id) {
        return compra.containsKey(id);
    }

}
