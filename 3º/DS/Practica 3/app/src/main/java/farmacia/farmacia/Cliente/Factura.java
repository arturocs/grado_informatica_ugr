package farmacia.farmacia.Cliente;

import java.util.ArrayList;
import java.util.HashMap;

public class Factura {
    private HashMap<Integer, ElementoFactura> listaProductos;
    private float total;

    Factura() {
        total = 0;
        listaProductos = new HashMap();
    }
    public ArrayList<ElementoFactura> getListaElementos() {
        ArrayList<ElementoFactura> elementos = new ArrayList();
        for (ElementoFactura linea : listaProductos.values())
            elementos.add(linea);
        return elementos;
    }
    public void aniadirProducto(ProductoGenerico producto, int cantidad) {
        ElementoFactura elemento = new ElementoFactura(producto, cantidad);
        listaProductos.put(producto.getId(), elemento);
        total += elemento.getPrecio_total();
    }

    public float getTotal() {
        return total;
    }


}
