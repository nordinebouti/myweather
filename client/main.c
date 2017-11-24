#include 		"client.h"

int 			main(int argc, char **argv)
{
    zsock_t 	*sub;
    char        *str_dprt;

    str_dprt = NULL;
    if (argc != 4) 
    {
        my_putstr("FATAL ERROR. Parameters required/weather-client [ip] [port-sub] [department]\n");
        return (0);
    }
    else
    {
        sub = zsock_new(ZMQ_SUB);
        zsock_connect(sub, "tcp://%s:%s", argv[1], argv[2]);
        zsock_set_subscribe(sub, argv[3]);
    }
    if (!sub)
    {
        my_putstr("FATAL ERROR. IMPOSSIBLE TO INITIALIZE. VERIFY PARAMETERS\n");
        return (0);
    }

    while (!zsys_interrupted) {
	    str_dprt = zstr_recv (sub);
    	show_details(str_dprt);
    	zstr_free(&str_dprt);
        sleep(5);
    }
    zsock_destroy(&sub);
    return (0);
}