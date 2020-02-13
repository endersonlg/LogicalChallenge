#define ALTURA 678
#define LARGURA 960

void tela_final(int *pontuacao,int *tempo)/*int *pontuacao, int *tempo)*/
{
    /**DECLARACAO VARIAVEL PONTEIRO*/
    ALLEGRO_BITMAP * fundo = NULL;/** PONTEIRO FUNDO*/
    ALLEGRO_BITMAP * gif[28];/// 28PONTEIRO GIF
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;/**PONTEIRO FILA DE EVENTOS*/
    ALLEGRO_FONT * fonte = NULL;/**PONTEIRO FONTE*/

    /**VARIAVEL PRIMITIVAS*/
    float pontuacao_final;
    int i,cor_verde,cor_vermelho;
    bool sair;

    /**ATRIBUICAO A VARIAVEL*/
    i=0;
    cor_verde=255;
    cor_vermelho=255;

    sair=false;

    fila_eventos = al_create_event_queue();/**CRIANDO FILA DE EVENTOS*/


    /**ATRIBUINDO IMAGEM A VARIAVEL PONTEIRO*/
    fundo= al_load_bitmap("recursos/pontuacao/fundo.jpg");/**menu recebe imagem**/

      if(*pontuacao>=4)
    {
        gif[0] = al_load_bitmap("recursos/pontuacao/passou/gif-0.png");/**IMAGENS GIFS*/
        gif[1] = al_load_bitmap("recursos/pontuacao/passou/gif-1.png");
        gif[2] = al_load_bitmap("recursos/pontuacao/passou/gif-2.png");
        gif[3] = al_load_bitmap("recursos/pontuacao/passou/gif-3.png");
        gif[4] = al_load_bitmap("recursos/pontuacao/passou/gif-4.png");
        gif[5] = al_load_bitmap("recursos/pontuacao/passou/gif-5.png");
        gif[6] = al_load_bitmap("recursos/pontuacao/passou/gif-6.png");
        gif[7] = al_load_bitmap("recursos/pontuacao/passou/gif-7.png");
        gif[8] = al_load_bitmap("recursos/pontuacao/passou/gif-8.png");
        gif[9] = al_load_bitmap("recursos/pontuacao/passou/gif-9.png");
        gif[10] = al_load_bitmap("recursos/pontuacao/passou/gif-10.png");
    }
    else
    {
        gif[0] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-1.png");/**IMAGENS GIFS*/
        gif[1] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-2.png");
        gif[2] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-3.png");
        gif[3] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-4.png");
        gif[4] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-5.png");
        gif[5] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-6.png");
        gif[6] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-7.png");
        gif[7] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-8.png");
        gif[8] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-9.png");
        gif[9] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-10.png");
        gif[10] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-11.png");
        gif[11] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-12.png");
        gif[12] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-13.png");
        gif[13] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-14.png");
        gif[14] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-15.png");
        gif[15] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-16.png");
        gif[16] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-17.png");
        gif[17] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-18.png");
        gif[18] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-19.png");
        gif[19] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-20.png");
        gif[20] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-21.png");
        gif[21] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-22.png");
        gif[22] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-23.png");/**IMAGENS GIFS*/
        gif[23] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-24.png");
        gif[24] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-25.png");
        gif[25] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-26.png");
        gif[26] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-27.png");
        gif[27] = al_load_bitmap("recursos/pontuacao/nao-passou/gif-28.png");

    }
    al_draw_bitmap(fundo,0,0,0);/**ONDE FUNDO IRA SE POSIOCIONAR*/
    al_flip_display();/**ATUALIZA A TELA*/

    al_register_event_source(fila_eventos, al_get_keyboard_event_source());/**REGISTRAR EVENTOS TELCADO*/
    al_register_event_source(fila_eventos, al_get_mouse_event_source());/**REGISTRA EVENTOS MOUSE*/



    if(*pontuacao==0)
    {
        pontuacao_final=0;
    }
    else
    {
        pontuacao_final= (float) pow(2,*pontuacao) / *tempo * 100;
        pontuacao_final=(int) pontuacao_final/1;
    }



    fonte = al_load_font("recursos/fonte_simpsons.OTF", 60, 0);///ATRIBUICAO DE FONTE
    al_draw_textf(fonte, al_map_rgb(0, 0, 0), LARGURA*0.05,ALTURA*0.27,0,"Pontos : %0.0f ",pontuacao_final);/**ESCREVER NA TELA USANDO A FONTE E LOCALIZACAO DE ONDE SE ENCONTRA A FONTE DESEJADA*/

    fonte = al_load_font("recursos/fonte_simpsons.OTF", 30, 0);/**ATRIBUICAO DE FONTE E LOCALIZACAO DE ONDE SE ENCONTRA A FONTE DESEJADA*/
    al_draw_textf(fonte, al_map_rgb(0, 0, 0), LARGURA*0.05,ALTURA*0.37,0,"Acertou : %i questoes",*pontuacao);

    al_draw_textf(fonte,al_map_rgb(0,0,0),LARGURA*0.5,ALTURA*0.37,0,"Tempo: %i min %i seg",*tempo/60,*tempo%60);///TEMPO ONDE IRA POSICONAR

    fonte=al_load_font("recursos/fonte_simpsons.OTF", 30,0);
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA*0.05,ALTURA*0.9,0,"Tela de Rank tecle Enter");/**ONDE O MENU BRANCO IRA SE POSICIONAR*/

    if(*pontuacao>=4)
    {
        while(!sair)
            {
                if(!al_is_event_queue_empty(fila_eventos))
                {
                    ALLEGRO_EVENT evento;/**CRIANDO FILA DE EVENTOS*/
                    al_wait_for_event(fila_eventos,&evento);
                    if(evento.type == ALLEGRO_EVENT_KEY_UP)
                    {
                        switch(evento.keyboard.keycode)/** EVENTO TECLADO*/
                        {
                        case ALLEGRO_KEY_ENTER:/**SE CLICAR EM enter tela de rank*/
                        sair=true;
                        break;
                        }
                    }
                }
                else
                {
                    al_draw_bitmap(gif[i],LARGURA*0.692,ALTURA*0.604,0);
                    fonte=al_load_font("recursos/fonte_simpsons.OTF", 100,0);
                    al_draw_text(fonte, al_map_rgb(cor_vermelho, cor_verde,0), LARGURA*0.2, ALTURA*0.1,0, "APROVADO!");
                    al_flip_display();
                    al_rest(0.1);
                    i++;
                    if(i==11)
                    {
                        i=0;
                    }
                    if(cor_vermelho==255)
                    {
                        cor_vermelho=0;
                    }
                    else
                    {
                        cor_vermelho=255;
                    }
                    if(cor_verde==255)
                    {
                        cor_verde=0;
                    }
                    else
                    {
                        cor_verde=255;
                    }
                }
            }
    }

    if(*pontuacao<4)
    {
        while(!sair)
            {
                if(!al_is_event_queue_empty(fila_eventos))
                {
                    ALLEGRO_EVENT evento;/**CRIANDO FILA DE EVENTOS*/
                    al_wait_for_event(fila_eventos,&evento);
                    if(evento.type == ALLEGRO_EVENT_KEY_UP)
                    {
                        switch(evento.keyboard.keycode)/** EVENTO TECLADO*/
                        {
                        case ALLEGRO_KEY_ENTER:/**SE CLICAR EM ESC SAIR*/
                        sair=true;
                        break;
                        }
                    }
                }
                else
                {
                    al_draw_bitmap(gif[i],LARGURA*0.696,ALTURA*0.57,0);
                    fonte=al_load_font("recursos/fonte_simpsons.OTF", 100,0);
                    al_draw_text(fonte, al_map_rgb(cor_vermelho, cor_verde,0), LARGURA*0.19, ALTURA*0.1,0, "REPROVADO!");
                    al_flip_display();
                    al_rest(0.1);
                    i++;
                    if(i==28)
                    {
                        i=0;
                    }
                    if(cor_vermelho==255)
                    {
                        cor_vermelho=0;
                    }
                    else
                    {
                        cor_vermelho=255;
                    }
                    if(cor_verde==255)
                    {
                        cor_verde=0;
                    }
                    else
                    {
                        cor_verde=255;
                    }
                }


            }
    }

    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());/**REGISTRAR EVENTOS TELCADO*/


    al_destroy_bitmap(fundo);
    if(*pontuacao<4)
    {
        for(i=0;i<28;i++)
        {
            al_destroy_bitmap(gif[i]);
        }
    }
    else
    {
        for(i=0;i<11;i++)
        {
            al_destroy_bitmap(gif[i]);
        }
    }
    *pontuacao=pontuacao_final;
    al_destroy_event_queue(fila_eventos);
    al_destroy_font(fonte);

}


