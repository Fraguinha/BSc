class Hello {

    private String message;

    public String getMessage() {

        return this.message;

    }

    public void setMessage(String message) {

        if (!message.isEmpty()) {

            this.message = message;

        }

    }

    public Hello() {

        this.message = "Hello, world.";

    }

    public Hello(String message) {

        if (!message.isEmpty()) {

            this.message = message;

        } else {

            this.message = "Hello, world.";

        }

    }

    public void sayMessage() {

        System.out.println(this.message);

    }

    public static void iAlwaysWork() {

        System.out.println("Im a static method");

    }

}