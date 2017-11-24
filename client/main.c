#include 		"client.h"

int 			main(int argc, char **argv)
{
    zsock_t 	*subscriber;
    char        *str_dprt;

    str_dprt = NULL;
    if (argc != 4) 
    {
        my_putstr("FATAL ERROR. Parameters required/weather-client [ip] [port-sub] [department]\n");
        return (0);
    }
    else
    {
        subscriber = zsock_new(ZMQ_SUB);
        zsock_connect(subscriber, "tcp://%s:%s", argv[1], argv[2]);
        zsock_set_subscribe(subscriber, argv[3]);
    }
    if (!subscriber)
    {
        my_putstr("Création du client impossible. Vérifier la valeur de vos paramètres.");
        return (0);
    }

    while (!zsys_interrupted) {
	    str_dprt = zstr_recv (subscriber);
    	show_details(str_dprt);
    	zstr_free(&str_dprt);
        sleep(5);
    }
    zsock_destroy(&subscriber);
    return (0);
}