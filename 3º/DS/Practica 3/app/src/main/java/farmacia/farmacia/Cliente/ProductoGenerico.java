package farmacia.farmacia.Cliente;

public abstract class ProductoGenerico {

    int id;
    String nombre;
    double precio;

    public int getId() {
        return id;
    }

    public String getNombre() {
        return nombre;
    }

    public double getPrecio() {
        return precio;
    }

    @Override
    public String toString() {
        return id + "," + nombre + "," + precio;
    }
}
