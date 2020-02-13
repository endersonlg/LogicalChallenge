#define ALTURA 678
#define LARGURA 960


void inicio()
{

    /**declaracao variaveis principais*/
    ALLEGRO_BITMAP * inicio[11];///VARIAVEIS PONTEIRO 11 IMAGEM
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;

    /**variavel contador*/
    int i;
    i=0;

    fila_eventos = al_create_event_queue();/**CRIAR FILA DE EVENTOS*/

    ///ATRIBUICAO DE IMAGEM
    inicio[0] = al_load_bitmap("recursos/inicio/logo.png");
    inicio[1] = al_load_bitmap("recursos/inicio/logo-0.png");
    inicio[2] = al_load_bitmap("recursos/inicio/logo-1.png");
    inicio[3] = al_load_bitmap("recursos/inicio/logo-2.png");
    inicio[4] = al_load_bitmap("recursos/inicio/logo-3.png");
    inicio[5] = al_load_bitmap("recursos/inicio/logo-4.png");
    inicio[6] = al_load_bitmap("recursos/inicio/logo-5.png");
    inicio[7] = al_load_bitmap("recursos/inicio/logo-6.png");
    inicio[8] = al_load_bitmap("recursos/inicio/logo-7.png");
    inicio[9] = al_load_bitmap("recursos/inicio/logo-8.png");
    inicio[10] = al_load_bitmap("recursos/inicio/logo-9.png");

    ///REGISTRA EVENTOS
    al_register_event_source(fila_eventos, al_get_mouse_event_source());///guardar registros

    for(i=0;i<11;i++)
    {
        al_draw_bitmap(inicio[i],0,0,0);
        al_flip_display();
        al_rest(0.05);

        if(i==0||i==10)
        {
            al_rest(2);
        }

    }

    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());///apagar registros

    for(i=0;i<11;i++)
    {
        al_destroy_bitmap(inicio[i]);///apagar bitmap 0 ate 11
    }
    al_destroy_event_queue(fila_eventos);///apagar fila de eventos

}
