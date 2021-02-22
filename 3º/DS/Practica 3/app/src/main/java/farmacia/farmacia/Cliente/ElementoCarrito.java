package farmacia.farmacia.Cliente;

public class ElementoCarrito {

    private ProductoGenerico producto;
    private int cantidad;

    ElementoCarrito(ProductoGenerico producto, int i) {
        this.producto = producto;
        cantidad = i;
    }

    public int getCantidad() {
        return cantidad;
    }

    public ProductoGenerico getProducto() {
        return producto;
    }

    public void aniadir(int i) {
        cantidad += i;
    }


    @Override
    public String toString() {
        return getCantidad() + "," + getProducto().toString();
    }


}
