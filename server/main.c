#include 		"serv.h"

int 			main(int argc, char **argv)
{
	char 		*str_dprt;
    zsock_t 	*req;
    zsock_t 	*pub;
    t_dpt		*list;
    
    str_dprt = NULL;
    list = NULL;
    list = malloc(sizeof(t_dpt));
    list->data = NULL;
    list->next = NULL;
    list->next = malloc(sizeof(t_dpt));
    list->data = NULL;
    
    if (argc != 4) 
    {
        my_putstr("Initialisation error. Parameters needed : ./weather-server [ip] [port-req] [port-pub]\n");
        return (0);
    }
    else
    {
        pub = zsock_new(ZMQ_PUB);
        zsock_bind(pub, "tcp://*:%s", argv[3]);
        req = zsock_new(ZMQ_REQ);
        zsock_connect(req, "tcp://%s:%s", argv[1], argv[2]);
    }

    if (!req || !pub)
    {
        my_putstr("FATAL ERROR. IMPOSSIBLE TO INITIALIZE. VERIFY PARAMETERS\n");
        return (0);
    }

    my_putstr("Ready to go !\n");
    while (!zsys_interrupted) {
        zstr_sendf(req, "france");
        str_dprt = zstr_recv(req);
        list = create_list(str_dprt);
        my_putstr("New datas upcoming\n");
        while (list != NULL)
    	{
    		zstr_sendf(pub, "%s", list->data);
            list = list->next;
    	}
        zstr_free(&str_dprt);
        my_putstr("Sending updated datas to client\n");
    	sleep(5);
    }
    zsock_destroy(&req);
    zsock_destroy(&pub);
    free(list);
    my_putstr("\nShuting down\n");
    return (0);
}