#define ALTURA 678
#define LARGURA 960


void tela_carregamento()
{

    /**declaracao variaveis principais*/
    ALLEGRO_BITMAP * fundo;
    ALLEGRO_BITMAP * gif[7];
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;

    /**variavel contador*/
    int i,j,contador;
    i=0;
    j=369;
    contador=369;

    fila_eventos = al_create_event_queue();/**CRIAR FILA DE EVENTOS*/

    /**atribuindo valores a variaveis*/
    fundo= al_load_bitmap("recursos/carregamento/carregamento0.jpg");/**menu recebe imagem**/

    gif[0] = al_load_bitmap("recursos/carregamento/gif1.png");
    gif[1] = al_load_bitmap("recursos/carregamento/gif2.png");
    gif[2] = al_load_bitmap("recursos/carregamento/gif3.png");
    gif[3] = al_load_bitmap("recursos/carregamento/gif4.png");
    gif[4] = al_load_bitmap("recursos/carregamento/gif5.png");
    gif[5] = al_load_bitmap("recursos/carregamento/gif6.png");
    gif[6] = al_load_bitmap("recursos/carregamento/gif7.png");

    al_draw_bitmap(fundo,0,0,0);

    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    for(j=369;j<=597;j++)
    {
        al_draw_filled_rectangle(369.0, 509.0, j, 540.0, al_map_rgb(255, 255, 255));
        al_flip_display();
        al_rest(0.04);
        if(contador+6<=j)///para movimentar o gif o a tela de loading  deve aumentar 6 pixel
        {
            contador=j;
            if(i==7)
            {
                i=0;
            }
            al_draw_bitmap(gif[i],LARGURA*0.41,ALTURA*0.35,0);
            i++;
            al_flip_display();///atualiza tela
        }
        j+=2;///j recebe mais 2 para aumentar a velocidade da barra de carregamento
    }

    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());///apagar registro mouse

    for(i=0;i<7;i++)
    {
        al_destroy_bitmap(gif[i]);
    }
    al_destroy_bitmap(fundo);
    al_destroy_event_queue(fila_eventos);

}
