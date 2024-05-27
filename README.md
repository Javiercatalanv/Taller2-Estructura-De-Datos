# Taller2-Estructura-De-Datos
Javier Alonso Catalán Vargas ; 21.445.807-1 ; javier.catalan01@alumnos.ucn.cl

# Objetos Creados en el Main:
Customers (4):
customer1:{type: "normal" , rut: "21.445.807-1", turn: 1}

customer1:{type: "pregnant" , rut: "26.432.678-4", turn: 2}

customer1:{type: "normal" , rut: "11.678.546-k", turn: 3}

customer1:{type: "Third Age" , rut: "8.987.356-7", turn: 4}

# Metodos Creados en el Main:
addCustomerToQueue(Customer *customer): Añade un cliente a su respectiva fila.
chooseType(): Permite elegir el tipo de cliente si es que este es preferente.
enterIntoQueue(int myTurn): Permite añadir un cliente.
deliverNumber(): Entrega el turno de atencion.
searchProduct(string nameProduct): Busca un producto en bodega.
giveReceipt(vector<pair<string, int>> cart): Entrega la boleta.
makeOrder(vector<pair<string, int>> cart,string products,int cant,pair<string,int> med,Customer *customer): Permite al cliente hacer su orden de medicamentos.
serveCustomer(Customer *customer): Permite al cliente hacer su orden.
callNextCustomer(): Llama al siguiente cliente.
addProduct(): Añade productos a la bodega.
customerMenu(): Abre el menu de los clientes.
access(): Comprueba el acceso al sistema de trabajador. (Único logIn)
workerMenu(): Despliega el menu trabajador.
saveWareHouse(): Guarda/actualiza la informacion de bodega.
globalMenu(): Da la opcion de seleccionar que menu desplegar.
readFile(string filename, HashMap& hashMap): Lee el archivo.
