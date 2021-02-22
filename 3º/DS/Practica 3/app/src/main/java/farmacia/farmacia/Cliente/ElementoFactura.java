package farmacia.farmacia.Cliente;

public class ElementoFactura {
    private String nombre;
    private int id;
    private int cantidad;
    private double precio_total;

    ElementoFactura(ProductoGenerico pro, int cantidad) {
        this.id = pro.getId();
        this.nombre = pro.getNombre();
        this.cantidad = cantidad;
        this.precio_total = pro.getPrecio() * cantidad;
    }

    public int getId() {
        return id;
    }

    public String getNombre() {
        return nombre;
    }

    public double getPrecio_total() {
        return precio_total;
    }

    @Override
    public String toString() {
        return nombre + ',' + cantidad + "," + precio_total;
    }
}
