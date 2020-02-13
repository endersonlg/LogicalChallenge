#define ALTURA 678
#define LARGURA 960


int fase13(int pontuacao)
{
    /**DECLARACAO DAS VARIAVEIS PRINCIAPAIS POR PONTEIRO*/
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;

    /**DECLARACAO DAS VARIAVEIS PONTEIRO - IMAGEM*/
    ALLEGRO_BITMAP * resposta1 = NULL;
    ALLEGRO_BITMAP * resposta11 = NULL;
    ALLEGRO_BITMAP * resposta2 = NULL;
    ALLEGRO_BITMAP * resposta22 = NULL;
    ALLEGRO_BITMAP * resposta3 = NULL;
    ALLEGRO_BITMAP * resposta33 = NULL;
    ALLEGRO_BITMAP * resposta4 = NULL;
    ALLEGRO_BITMAP * resposta44 = NULL;
    ALLEGRO_BITMAP * resposta5 = NULL;
    ALLEGRO_BITMAP * resposta55 = NULL;
    ALLEGRO_BITMAP * resposta_correta= NULL;

    /**DECLARACAO VARIAVEIS PONTEIRO - AUDIO*/
    ALLEGRO_SAMPLE * errou = NULL;
    ALLEGRO_SAMPLE * acerto = NULL;
    ALLEGRO_SAMPLE * click = NULL;

    /**DECLARACAO DAS VARIAIS BOOLEANAS*/
    bool sair,opcao1,opcao2,opcao3,opcao4,opcao5;
    opcao1=true;
    opcao2=true;
    opcao3=true;
    opcao4=true;
    opcao5=true;
    sair=false;

    /**DECLARACAO DAS VARIAVEIS INTEIRAS*/
    int ponto;
    ponto=-1;///recebe menos 1 para nao dar problema no switch

    /**CRIANDO FILA DE EVENTOS*/
    fila_eventos = al_create_event_queue();///criacao da fila de eventos

    fundo = al_load_bitmap("recursos/pergunta13/pergunta.jpg");/**FUNDO RECEBE IMAGEM E SUA LOCALIZACAO DE ONDE ELA ESTA**/
    al_draw_bitmap(fundo,0,0,0);/**ONDE A IMAGEM IRA SE POSICIONAR*/
    al_flip_display();/**ATUALIZA TELA*/

    errou=al_load_sample("recursos/errou.ogg");/**ERROU RECEBE AUDIO CURTO E SUA LOCALIZACAO*/
    acerto=al_load_sample("recursos/acerto.ogg");/**ACERTOU RECEBE AUDIO CURTO E SUA LOCALIZACAO*/
    click=al_load_sample("recursos/click.ogg");/**ERROU RECEBE AUDIO CURTO E SUA LOCALIZACAO*/

    /**ATRIBUINDO IMAGEM*/
    resposta1=al_load_bitmap("recursos/pergunta13/resposta1.png");
    resposta11=al_load_bitmap("recursos/pergunta13/resposta11.png");
    resposta2=al_load_bitmap("recursos/pergunta13/resposta2.png");
    resposta22=al_load_bitmap("recursos/pergunta13/resposta22.png");
    resposta3=al_load_bitmap("recursos/pergunta13/resposta3.png");
    resposta33=al_load_bitmap("recursos/pergunta13/resposta33.png");
    resposta4=al_load_bitmap("recursos/pergunta13/resposta4.png");
    resposta44=al_load_bitmap("recursos/pergunta13/resposta44.png");
    resposta5=al_load_bitmap("recursos/pergunta13/resposta5.png");
    resposta55=al_load_bitmap("recursos/pergunta13/resposta55.png");
    resposta_correta=al_load_bitmap("recursos/pergunta13/respostacorreta.png");

    /**ONDE A IMAGENS IRA SE POSICIONAR*/
    al_draw_bitmap(resposta1, LARGURA*0.144, ALTURA*0.494,0);
    al_draw_bitmap(resposta2, LARGURA*0.144, ALTURA*0.601,0);
    al_draw_bitmap(resposta3, LARGURA*0.144, ALTURA*0.705,0);
    al_draw_bitmap(resposta4, LARGURA*0.144, ALTURA*0.811,0);
    al_draw_bitmap(resposta5, LARGURA*0.144, ALTURA*0.916,0);
    al_flip_display();

    al_register_event_source(fila_eventos, al_get_keyboard_event_source());/**REGISTRAR EVENTOS TELCADO*/
    al_register_event_source(fila_eventos, al_get_mouse_event_source());/**REGISTRAR EVENTOS MOUSE*/

    while(!sair)/**SAIR JO JOGO*/
    {
        ALLEGRO_EVENT evento;/**CRIANDO FILA DE EVENTOS*/
        al_wait_for_event(fila_eventos,&evento);

        if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)/**SOM DE CLIQUE*/
        {
            al_play_sample(click,1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        }
        if(opcao1)///SE VERDADEIRO MOSTRA A IMAGEM COM SOMBRA
        {
            al_draw_bitmap(resposta1, LARGURA*0.144, ALTURA*0.494,0);
        }
        else
        {
            al_draw_bitmap(resposta11, LARGURA*0.144, ALTURA*0.494,0);
        }
        al_flip_display();///ATUALIZA A TELA

        if(evento.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            if(evento.mouse.x > LARGURA*0.144 && evento.mouse.x < LARGURA*0.144 + al_get_bitmap_width(resposta1) && evento.mouse.y> ALTURA*0.494 && evento.mouse.y < ALTURA*0.494 + al_get_bitmap_height(resposta1))
            {
                opcao1=false;
            }
            else
            {
                opcao1=true;
            }
        }
        if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)///CASO CLIQUE NA RESPOSTA
        {
            if(evento.mouse.x > LARGURA*0.144 && evento.mouse.x < LARGURA*0.144 + al_get_bitmap_width(resposta1))
            {
                if(evento.mouse.y > ALTURA*0.494 && evento.mouse.y < ALTURA*0.494 + al_get_bitmap_height(resposta1))
                {

                    ponto=0;
                }
            }
        }
        if(opcao2)
        {
            al_draw_bitmap(resposta2, LARGURA*0.144, ALTURA*0.601,0);
        }
        else
        {
            al_draw_bitmap(resposta22, LARGURA*0.144, ALTURA*0.601,0);
        }
        al_flip_display();
        if(evento.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            if(evento.mouse.x > LARGURA*0.144 && evento.mouse.x < LARGURA*0.144 + al_get_bitmap_width(resposta2) && evento.mouse.y> ALTURA*0.601 && evento.mouse.y < ALTURA*0.601 + al_get_bitmap_height(resposta2))
            {
                opcao2=false;
            }
            else
            {
                opcao2=true;
            }
        }
        if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        {
            if(evento.mouse.x > LARGURA*0.144 && evento.mouse.x < LARGURA*0.144 + al_get_bitmap_width(resposta2))
            {
                if(evento.mouse.y > ALTURA*0.601 && evento.mouse.y < ALTURA*0.601 + al_get_bitmap_height(resposta2))
                {

                    ponto=0;
                }
            }
        }
        if(opcao3)
        {
            al_draw_bitmap(resposta3, LARGURA*0.144, ALTURA*0.705,0);
        }
        else
        {
            al_draw_bitmap(resposta33, LARGURA*0.144, ALTURA*0.705,0);
        }
        al_flip_display();
        if(evento.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            if(evento.mouse.x > LARGURA*0.144 && evento.mouse.x < LARGURA*0.144 + al_get_bitmap_width(resposta3) && evento.mouse.y> ALTURA*0.705 && evento.mouse.y < ALTURA*0.705 + al_get_bitmap_height(resposta3))
            {
                opcao3=false;
            }
            else
            {
                opcao3=true;
            }
        }
        if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        {
            if(evento.mouse.x > LARGURA*0.144 && evento.mouse.x < LARGURA*0.144 + al_get_bitmap_width(resposta4))
            {
                if(evento.mouse.y > ALTURA*0.705 && evento.mouse.y < ALTURA*0.705 + al_get_bitmap_height(resposta4))
                {

                    ponto=1;/**SE VERDADEIRO RECEBE 1 PARA NAO PASSAR PELA RESPOSTA ERRADA*/
                }
            }
        }
        if(opcao4)
        {
            al_draw_bitmap(resposta4, LARGURA*0.144, ALTURA*0.811,0);
        }
        else
        {
            al_draw_bitmap(resposta44, LARGURA*0.144, ALTURA*0.811,0);
        }
        al_flip_display();
        if(evento.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            if(evento.mouse.x > LARGURA*0.144 && evento.mouse.x < LARGURA*0.144 + al_get_bitmap_width(resposta4) && evento.mouse.y> ALTURA*0.811 && evento.mouse.y < ALTURA*0.811 + al_get_bitmap_height(resposta4))
            {
                opcao4=false;
            }
            else
            {
                opcao4=true;
            }
        }
        if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        {
            if(evento.mouse.x > LARGURA*0.144 && evento.mouse.x < LARGURA*0.144 + al_get_bitmap_width(resposta4))
            {
                if(evento.mouse.y > ALTURA*0.811 && evento.mouse.y < ALTURA*0.811 + al_get_bitmap_height(resposta4))
                {
                    ponto=0;
                }
            }
        }
        if(opcao5)
        {
            al_draw_bitmap(resposta5, LARGURA*0.144, ALTURA*0.916,0);
        }
        else
        {
            al_draw_bitmap(resposta55, LARGURA*0.144, ALTURA*0.916,0);
        }
        al_flip_display();
        if(evento.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            if(evento.mouse.x > LARGURA*0.144 && evento.mouse.x < LARGURA*0.144 + al_get_bitmap_width(resposta5) && evento.mouse.y> ALTURA*0.916 && evento.mouse.y < ALTURA*0.916 + al_get_bitmap_height(resposta5))
            {
                opcao5=false;
            }
            else
            {
                opcao5=true;
            }
        }
        if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)/**SE CLICAR NA PERGUNTA*/
        {
            if(evento.mouse.x > LARGURA*0.144 && evento.mouse.x < LARGURA*0.144 + al_get_bitmap_width(resposta5))
            {
                if(evento.mouse.y > ALTURA*0.918 && evento.mouse.y < ALTURA*0.916 + al_get_bitmap_height(resposta5))
                {
                    ponto=0;
                }
            }
        }

        switch (ponto)///SE RESPOSTA ESTIVER ERRADA MOSTRAR A CORRETA
            {
            case 0:
                al_play_sample(errou,2.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                al_draw_bitmap(resposta_correta,LARGURA*0.144, ALTURA*0.705,0);///RESPOSTA CORRETA
                al_flip_display();
                al_rest(2);///TEMPO 2 SEGUNDO
                sair=true;
               break;

              case 1:
                al_play_sample(acerto,2.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                al_rest(2);
                sair=true;
                break;
            }

        if(evento.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(evento.keyboard.keycode)/** EVENTO TECLADO*/
            {
                case ALLEGRO_KEY_ESCAPE:/**SE CLICAR EM ESC SAIR*/
                sair = true;
                ponto=-100;/**RECEBE MENOS 100 PARA NAO IR PARA A PROXIMA FASE*/
                break;
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());/**APAGAR REGISTRO*/
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());

    al_destroy_bitmap(fundo);
    al_destroy_event_queue(fila_eventos);
    al_destroy_bitmap(resposta1);
    al_destroy_bitmap(resposta11);
    al_destroy_bitmap(resposta2);
    al_destroy_bitmap(resposta22);
    al_destroy_bitmap(resposta3);
    al_destroy_bitmap(resposta33);
    al_destroy_bitmap(resposta4);
    al_destroy_bitmap(resposta44);
    al_destroy_bitmap(resposta5);
    al_destroy_bitmap(resposta55);
    al_destroy_bitmap(resposta_correta);
    al_destroy_sample(click);
    al_destroy_sample(errou);
    al_destroy_sample(acerto);

    return ponto;
}
