#include 		"serv.h"

int 			main(int argc, char **argv)
{
	char 		*str_dprt;
    zsock_t 	*req;
    zsock_t 	*publisher;
    t_dpt		*list;
    int         i = 0;
    
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
        publisher = zsock_new(ZMQ_PUB);
        zsock_bind(publisher, "tcp://*:%s", argv[3]);
        req = zsock_new(ZMQ_REQ);
        zsock_connect(req, "tcp://%s:%s", argv[1], argv[2]);
    }

    if (!req || !publisher)
    {
        my_putstr("Création du serveur impossible. Vérifier la valeur de vos paramètres.");
        return (0);
    }
    my_putstr("Serveur lancé\n");
    while (!zsys_interrupted) {
        zstr_sendf(req, "france");
        my_putstr("Récupération des données...\n");
        str_dprt = zstr_recv(req);
        list = create_list(str_dprt);
        while (list != NULL)
    	{
            ++i;
    		zstr_sendf(publisher, "%s", list->data);
            list = list->next;
    	}
        i = 0;
        zstr_free(&str_dprt);
        my_putstr("Sending updated datas to client\n");
    	sleep(5);
    }
    zsock_destroy(&req);
    zsock_destroy(&publisher);
    free(list);
    my_putstr("\nServeur hors ligne ! Au revoir ;)\n");
    return (0);
}