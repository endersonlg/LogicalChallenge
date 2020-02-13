#include <stdio.h>///BIBLIOTECA PARA USAR OS RECURSOS BASICOS
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>///USAR TEMPO
#include <Allegro5/allegro.h>///FUNCOES BASICAS DO ALLEGRO
#include <Allegro5/allegro_image.h>///IMAGEM
#include <allegro5/allegro_font.h>///BIBLIOTECA FONTE
#include <allegro5/allegro_ttf.h>///FONTE PADRAO TTF
#include <allegro5/allegro_audio.h>///BIBLIOTECA AUDIO
#include <allegro5/allegro_acodec.h>///ADUIO
#include <allegro5/allegro_native_dialog.h>///MENSAGENS  display
#include <allegro5/allegro_primitives.h>///FORMAS BASICAS PRIMITIVAS
#include "fase1.h"///FASES 1 a 12
#include "fase2.h"
#include "fase3.h"
#include "fase4.h"
#include "fase5.h"
#include "fase6.h"
#include "fase7.h"
#include "fase8.h"
#include "fase9.h"
#include "fase10.h"
#include "fase11.h"
#include "fase12.h"
#include "fase13.h"
#include "fase14.h"
#include "fase15.h"
#include "fase16.h"
#include "fase17.h"
#include "fase18.h"
#include "carregamento.h"///TELA DE CARREGAMENTO
#include "pontuacao.h"///TELA DE PONTUACAO
#include "inicio.h"///IMAGEM FAITEC E LOGO

#define LARGURA 960
#define ALTURA  678


char nome[17];

int main()
{
    /**DECLARACAO VARIAVEIS PONTEIRO BIBLIOTECA ALLEGRO*/
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo_menu = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_AUDIO_STREAM * musica = NULL;
    ALLEGRO_SAMPLE * click = NULL;
    ALLEGRO_FONT * fonte = NULL;

    /**DECLARACAO VARIAVEIS TEXTO USANDO PONTEIRO*/
    char * jogar_texto="Jogar";
    char * sair_texto="Sair";

    char primeiro_lugar[17],segundo_lugar[17],terceiro_lugar[17];
    char primeiro_pontuacao[10],segundo_pontuacao[10],terceiro_pontuacao[10],pontuacao_atual[10];

    time_t tempo1, tempo2, tempo;///USAR TEMPO FINAL - TEMPO Q INICIOU

    /**DECLARACAO VARIAVEIS*/
    int vetor[18];
    int pontuacao,primeiro,segundo,terceiro,i, k;;
    bool jogar,ativo,sair;
    bool concluido = false;

    /**ATRIBUICAO DE VALORES*/
    ativo=false;
    jogar=false;
    sair=false;
    strcpy( primeiro_lugar, "NOME");
    strcpy( segundo_lugar, "NOME");
    strcpy( terceiro_lugar, "NOME");
    pontuacao=0;
    primeiro=0;
    segundo=0;
    terceiro=0;


    srand(time(NULL));


    /**INICIAR*/
    al_init();/**INICIAR PROGRAMA*/
    al_init_image_addon();/**INICIAR USO DE IMAGEM*/
    al_init_primitives_addon();/**INICIAR  USO DE IMAGENS PRIMITIVAS*/
    al_init_font_addon();/**INICIAR USO DE FONTES*/
    al_init_ttf_addon();/**INICIAR USO DE FONTES FORMATO TFF*/

    al_install_audio(); /**INSTALAR AUDIO*/
    al_init_acodec_addon();/**INICIAR O USO DE AUDIOS*/
    al_reserve_samples(9);/**QUANTIDADES DE AUDIOS QUE SERA REPRODUZIDOS*/

    janela = al_create_display(LARGURA,ALTURA);/**CRIACAO DA JANELA*/

    fila_eventos = al_create_event_queue();/**CRIACAO DA FILA DE EVENTOS*/

    al_install_mouse();/**INSTALAR MOUSE*/
    al_install_keyboard();/**INSTALAR TECLADO*/

    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);/**ONDE MOUSE SERA USADO - JANELA*/

    inicio();///CHAMAR TELA DE INTRODUCAO

    /**ATRIBUICAO DE SONS*/
    musica = al_load_audio_stream("recursos/musica.ogg",4,1024);/**AUDIO DE LONGA DURACAO*/
    click=al_load_sample("recursos/click.ogg");/**AUDIO DE PEQUENA DURACAO*/
    al_attach_audio_stream_to_mixer(musica, al_get_default_mixer()); /**PARA O AUDIO DE LONGA DURACAO COMECAR A REPRODUZIR*/
    al_set_audio_stream_playmode(musica, ALLEGRO_PLAYMODE_LOOP); /**PARA DEIXAR AUDIO EM LOOP*/

    /**FONTE*/
    fonte = al_load_font("recursos/bad Gong.TTF", 90, 0);/**ATRIBUICAO DE FONTE E LOCALIZACAO DE ONDE SE ENCONTRA A FONTE DESEJADA*/

    fundo_menu = al_load_bitmap("recursos/fundo.jpg");/**ATRIBUICAO DE IMAGEM PARA TELA DE FUNDO*/
    al_draw_bitmap(fundo_menu,0,0,0);/**ONDE A IMAGEM SERA COLOCADA*/
    al_flip_display();/**ATUALIZAR TELA*/

    /**IMAGENS INICIAIS DO MENU PRINCIPAL*/
    al_draw_text(fonte, al_map_rgb(255, 255, 255), LARGURA*0.25,ALTURA*0.48,0,jogar_texto);/**IMAGEM JOGAR EM BRANCO*/
    al_draw_text(fonte, al_map_rgb(255, 255, 255), LARGURA*0.25,ALTURA*0.70,0, sair_texto);/**IMAGEM SAIR EM BRANCO*/
    al_flip_display();/**ATUALIZAR A TELA*/

    /**REGISTRAR EVENTOS*/
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));/**EVENTO DISPLAY JANELA*/
    al_register_event_source(fila_eventos, al_get_mouse_event_source());/**EVENTOS MOUSE*/
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());/**EVENTOS TECLADO*/

    while(!ativo)/**JOGO COMECA AQUI*/
    {

        while(!al_is_event_queue_empty(fila_eventos))/**DEIXAR JOGO EM LOOP*/
        {

            ALLEGRO_EVENT evento;/**CRIANDO EVENTO PARA FILA DE EVENTOS*/
            al_wait_for_event(fila_eventos,&evento);

            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)/**PARA HABILITAR O FECHAR NO CANTO SUPERIOR DIREITO*/
            {
                if (al_show_native_message_box(al_get_current_display(), "Logical Challenge",/**MENSAGEM QUE IRA APARECER CASO CLIQUE NO X*/
                    "Fechar Programa", "Deseja encerrar o programa?",
                    NULL, ALLEGRO_MESSAGEBOX_OK_CANCEL))

                {
                    ativo = true;/**SAIR DO JOGO*/
                }
            }

            if(jogar)/**SE JOGAR POSITIVA MOSTRAR A PALAVRA JOGAR EM AMARELO SENAO BRANCA*/
            {
               al_draw_text(fonte, al_map_rgb(255, 242, 0), LARGURA*0.25,ALTURA*0.48,0,jogar_texto);/**ONDE O JOGAR AMARELO IRA SE POSICIONAR*/
            }
            else
            {
              al_draw_text(fonte, al_map_rgb(255, 255, 255), LARGURA*0.25,ALTURA*0.48,0,jogar_texto);/**ONDE O JOGAR BRANCO IRA SE POSICIONAR*/
            }
            al_flip_display();/**ATUALIZA TELA*/

           if(evento.type == ALLEGRO_EVENT_MOUSE_AXES)/**MOUSE EM CIMA DA PALAVRA JOGAR COR AMARELA SENAO BRANCA - COLISAO*/
            {
                if(evento.mouse.x > LARGURA*0.25 && evento.mouse.x < LARGURA*0.25 + al_get_text_width(fonte,jogar_texto) && evento.mouse.y> ALTURA*0.48 && evento.mouse.y < ALTURA*0.48 +90 )/**90 = TAMANHO DA FONTE*/
                {
                    jogar=true;
                }
                else
                {
                    jogar=false;
                }
            }
            if(evento.type==ALLEGRO_EVENT_MOUSE_BUTTON_UP)/**SOM  DE CLIQUE*/
            {
                al_play_sample(click,1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            }

            if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)///SE CLICAR EM INICIAR botao esquerdo
            {
                if(evento.mouse.x > LARGURA*0.25 && evento.mouse.x < LARGURA*0.25 + al_get_text_width(fonte,jogar_texto))
                {
                    if(evento.mouse.y > ALTURA*0.48 && evento.mouse.y < ALTURA*0.48 + 90 )/**90 = TAMANHO DA FONTE*/
                    {

                        al_unregister_event_source(fila_eventos, al_get_mouse_event_source());/**PARAR DE  REGISTRAR MOUSE*/


                        pontuacao=0;/**PONTUACAO RECEBE 0 POIS SE A PESSOA JOGAR E DEPOIS JOGAR NOVAMENTE A PONTUACAO ZERAR*/
                        tempo=0;/**TEMPO RECEBE 0 POIS SE A PESSOA JOGAR E DEPOIS JOGAR NOVAMENTE O TEMPO ZERAR*/
                        tela_carregamento();/**CHAMA A TELA DE CARREGAMENTO*/
                        fundo_menu = al_load_bitmap("recursos/nomefundo.jpg");/**ATRIBUICAO DE IMAGEM PARA TELA DE FUNDO*/
                        fonte = al_load_font("recursos/fonte_simpsons.otf", 90, 0);/**ATRIBUICAO DE FONTE E LOCALIZACAO DE ONDE SE ENCONTRA A FONTE DESEJADA*/

                        while (!sair)
                        {
                            while (!al_is_event_queue_empty(fila_eventos))
                            {

                                al_wait_for_event(fila_eventos, &evento);
                                if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)/**PARA HABILITAR O FECHAR NO CANTO SUPERIOR DIREITO*/
                                {
                                    if (al_show_native_message_box(al_get_current_display(), "Logical Challenge",/**MENSAGEM QUE IRA APARECER CASO CLIQUE NO X*/
                                    "Fechar Programa", "Deseja encerrar o programa?",
                                    NULL, ALLEGRO_MESSAGEBOX_OK_CANCEL))

                                    {
                                        ativo = true;/**SAIR DO JOGO*/
                                        pontuacao=-100;
                                    }
                                }
                                if (!concluido)
                                {
                                    if (evento.type == ALLEGRO_EVENT_KEY_CHAR)
                                    {
                                        if (strlen(nome) <= 16)
                                        {
                                            char temp[] = {evento.keyboard.unichar, '\0'};
                                            if (evento.keyboard.unichar == ' ')
                                            {
                                                strcat(nome, temp);
                                            }
                                            else if (evento.keyboard.unichar >= '0' &&
                                                    evento.keyboard.unichar <= '9')
                                            {
                                                strcat(nome, temp);
                                            }
                                            else if (evento.keyboard.unichar >= 'A' &&
                                                    evento.keyboard.unichar <= 'Z')
                                            {
                                                strcat(nome, temp);
                                            }
                                            else if (evento.keyboard.unichar >= 'a' &&
                                                    evento.keyboard.unichar <= 'z')
                                            {
                                                strcat(nome, temp);
                                            }
                                        }

                                        if (evento.keyboard.keycode == ALLEGRO_KEY_BACKSPACE && strlen(nome) != 0)
                                        {
                                            nome[strlen(nome) - 1] = '\0';
                                        }
                                    }

                                    if (evento.type == ALLEGRO_EVENT_KEY_DOWN && evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                                    {
                                        concluido = true;
                                    }
                                }

                                if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                                {
                                    sair = true;
                                }
                            }

                            al_draw_bitmap(fundo_menu, 0, 0, 0);
                            al_draw_textf(fonte, al_map_rgb(255, 255, 0), LARGURA*0.05,ALTURA*0.42,0,"Nome");

                            if (strlen(nome) > 0)
                            {
                                al_draw_text(fonte, al_map_rgb(255, 255, 255), LARGURA*0.4,
                                            (ALTURA - al_get_font_ascent(fonte)) / 2,
                                            0, nome);
                            }
                            if(concluido==true)
                            {
                                sair=true;
                            }

                            al_flip_display();
                        }
                        sair=false;
                        concluido=false;

                        tempo1=time(NULL);/**PEGA A HORA INICIAL EM QUE COMECOU O JOGO*/

                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());/**PARA DE REGISTRAR TECLADO*/

                        fundo_menu = al_load_bitmap("recursos/fundo.jpg");
                        fonte = al_load_font("recursos/bad Gong.TTF", 90, 0);

                        for(i = 0; i < 18; i++)
                        {
                            vetor[i] = rand()%18;
                            for(k = 0; k < i; k++)
                            {
                                if(vetor[k] == vetor[i])
                                {
                                    vetor[i] = rand()%18;
                                    k = 0;
                                }
                            }

                        }
                        for(i = 0; i < 8; i++)
                        {
                            switch (vetor[i])
                            {
                                case 0:if(pontuacao>=0)
                                        {
                                            pontuacao=pontuacao+fase1(pontuacao);
                                        }
                                        break;
                                case 1:if(pontuacao>=0)
                                        {
                                            pontuacao=pontuacao+fase2(pontuacao);
                                        }
                                        break;
                                case 2:if(pontuacao>=0)
                                        {
                                            pontuacao=pontuacao+fase3(pontuacao);
                                        }
                                        break;
                                case 3:if(pontuacao>=0)
                                        {
                                            pontuacao=pontuacao+fase4(pontuacao);
                                        }
                                        break;
                                case 4:if(pontuacao>=0)
                                        {
                                            pontuacao=pontuacao+fase5(pontuacao);
                                        }
                                        break;
                                case 5:if(pontuacao>=0)
                                        {
                                            pontuacao=pontuacao+fase6(pontuacao);
                                        }
                                        break;
                                case 6:if(pontuacao>=0)
                                        {
                                            pontuacao=pontuacao+fase7(pontuacao);
                                        }
                                        break;
                                case 7:if(pontuacao>=0)
                                        {
                                            pontuacao=pontuacao+fase8(pontuacao);
                                        }
                                        break;
                                case 8:if(pontuacao>=0)
                                        {
                                            pontuacao=pontuacao+fase9(pontuacao);
                                        }
                                        break;
                                case 9:if(pontuacao>=0)
                                        {
                                            pontuacao=pontuacao+fase10(pontuacao);
                                        }
                                        break;
                                case 10:if(pontuacao>=0)
                                        {
                                            pontuacao=pontuacao+fase11(pontuacao);
                                        }
                                        break;
                                case 11:if(pontuacao>=0)
                                        {
                                            pontuacao=pontuacao+fase12(pontuacao);
                                        }
                                        break;
                                case 12:if(pontuacao>=0)
                                        {
                                            pontuacao=pontuacao+fase13(pontuacao);
                                        }
                                        break;
                                case 13:if(pontuacao>=0)
                                        {
                                            pontuacao=pontuacao+fase14(pontuacao);
                                        }
                                        break;
                                case 14:if(pontuacao>=0)
                                        {
                                            pontuacao=pontuacao+fase15(pontuacao);
                                        }
                                        break;
                                case 15:if(pontuacao>=0)
                                        {
                                            pontuacao=pontuacao+fase16(pontuacao);
                                        }
                                        break;
                                case 16:if(pontuacao>=0)
                                        {
                                            pontuacao=pontuacao+fase17(pontuacao);
                                        }
                                        break;
                                case 17:if(pontuacao>=0)
                                        {
                                            pontuacao=pontuacao+fase18(pontuacao);
                                        }
                                        break;
                            }
                        }

                        if(pontuacao>=0)/**SE PONTUACAO MAIOR QUE ZERO CHAMA A TELA FINAL POIS SE A PESSOA CLICAR EM ESC NA ULTIMA FASE NAO IRA PARA A FASE DE PONTUACAO*/
                        {
                            tempo2=time(NULL);/**TEMPO EM QUE ELE TERMINO O JOGO*/
                            tempo = difftime(tempo2, tempo1);/**SUBTRAIR O TEMPO EM QUE TERMINOU - O TEMPO EM QUE COMECOU PARA MOSTRAR O TEMPO DE JOGO*/
                            tela_final(&pontuacao,&tempo);/**CHAMA A TELA DE PONTUACAO MANDANDO EM REFERENCIA A PONTUACAO E O TEMPO*/
                            if(pontuacao>primeiro)
                            {
                                terceiro=segundo;
                                strcpy (terceiro_lugar, segundo_lugar);
                                segundo=primeiro;
                                strcpy (segundo_lugar, primeiro_lugar);
                                primeiro=pontuacao;
                                strcpy (primeiro_lugar, nome);
                            }
                            else if(pontuacao>segundo)
                            {
                                terceiro=segundo;
                                strcpy (terceiro_lugar, segundo_lugar);
                                segundo=pontuacao;
                                strcpy (segundo_lugar, nome);
                            }
                            else if(pontuacao>terceiro)
                            {
                                terceiro=pontuacao;
                                strcpy (terceiro_lugar, nome);
                            }

                            itoa(pontuacao,pontuacao_atual,10);
                            itoa(primeiro,primeiro_pontuacao,10);
                            itoa(segundo,segundo_pontuacao,10);
                            itoa(terceiro,terceiro_pontuacao,10);

                            fundo_menu = al_load_bitmap("recursos/nomefundo.jpg");/**ATRIBUICAO DE IMAGEM PARA TELA DE FUNDO*/
                            fonte = al_load_font("recursos/fonte_simpsons.otf", 70, 0);/**ATRIBUICAO DE FONTE E LOCALIZACAO DE ONDE SE ENCONTRA A FONTE DESEJADA*/

                            al_draw_bitmap(fundo_menu, 0, 0, 0);
                            al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA*0.43,ALTURA*0.3,0,"Rank");

                            fonte = al_load_font("recursos/fonte_simpsons.otf", 50, 0);/**ATRIBUICAO DE FONTE E LOCALIZACAO DE ONDE SE ENCONTRA A FONTE DESEJADA*/

                            al_draw_text(fonte, al_map_rgb(195, 195, 195), LARGURA*0.25,ALTURA*0.45,0,primeiro_lugar);
                            al_draw_text(fonte, al_map_rgb(195, 195, 195), LARGURA*0.65,ALTURA*0.45,0,primeiro_pontuacao);
                            al_draw_text(fonte, al_map_rgb(195, 195, 195), LARGURA*0.25,ALTURA*0.55,0,segundo_lugar);
                            al_draw_text(fonte, al_map_rgb(195, 195, 195), LARGURA*0.65,ALTURA*0.55,0,segundo_pontuacao);
                            al_draw_text(fonte, al_map_rgb(195, 195, 195), LARGURA*0.25,ALTURA*0.65,0,terceiro_lugar);
                            al_draw_text(fonte, al_map_rgb(195, 195, 195), LARGURA*0.65,ALTURA*0.65,0,terceiro_pontuacao);
                            al_draw_text(fonte, al_map_rgb(255, 0, 0), LARGURA*0.25,ALTURA*0.8,0,nome);
                            al_draw_text(fonte, al_map_rgb(255, 0, 0), LARGURA*0.65,ALTURA*0.8,0,pontuacao_atual);
                            fonte = al_load_font("recursos/fonte_simpsons.otf", 20, 0);/**ATRIBUICAO DE FONTE E LOCALIZACAO DE ONDE SE ENCONTRA A FONTE DESEJADA*/
                            al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA*0.02,ALTURA*0.95,0,"Para voltar ao Menu Tecle Enter");/**ONDE O MENU BRANCO IRA SE POSICIONAR*/


                            al_flip_display();
                            al_register_event_source(fila_eventos, al_get_keyboard_event_source());/**PARA DE REGISTRAR TECLADO*/
                            while (!sair)
                            {
                                while(!al_is_event_queue_empty(fila_eventos))
                                {
                                    al_wait_for_event(fila_eventos, &evento);
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
                            }
                            al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());/**PARA DE REGISTRAR TECLADO*/
                            sair=false;
                        }
                        fundo_menu = al_load_bitmap("recursos/fundo.jpg");
                        fonte = al_load_font("recursos/bad Gong.TTF", 90, 0);

                        strcpy (nome,"");
                        al_draw_bitmap(fundo_menu,0,0,0);/**MOSTRAR A TELA INICIAL POIS SE NAO DEMORARIA ALGUNS MINI SEGUNDO PARA MOSTRAR*/
                        al_draw_text(fonte, al_map_rgb(255, 255, 255), LARGURA*0.25,ALTURA*0.48,0, jogar_texto);/** MOSTRAR A PALAVRA JOGAR POIS SE NAO DEMORARIA ALGUNS MINI SEGUNDO PARA MOSTRAR*/

                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());/**REGISTRAR EVENTOS TELCADO*/
                        al_register_event_source(fila_eventos, al_get_mouse_event_source());/**REGISTRAR EVENTOS MOUSE*/

                    }
                }
            }

            if(sair)/**SE SAIR POSITIVO MOSTRAR ESCRITA SAIR EM AMARELO SENAO BRANCA*/
            {
                al_draw_text(fonte, al_map_rgb(255, 242, 0), LARGURA*0.25,ALTURA*0.70,0, sair_texto);/**ONDE A ESCRITA AMARELA IRA SE POSICIONAR*/
            }
            else
            {
                al_draw_text(fonte, al_map_rgb(255, 255, 255), LARGURA*0.25,ALTURA*0.70,0, sair_texto);/**ONDE A ESCRITA BRANCA IRA SE POSICIONAR*/
            }

            al_flip_display();/**ATUALIZA A TELA*/

            if(evento.type == ALLEGRO_EVENT_MOUSE_AXES)/**SE OCORRER COLISAO PALAVRA SAIR VERDADEIRO RECEBE TRUE QUE IRA APARECER AMARELO SENAO BRANCA*/
            {
                if(evento.mouse.x > LARGURA*0.25 && evento.mouse.x < LARGURA*0.25 + al_get_text_width(fonte, sair_texto) && evento.mouse.y> ALTURA*0.7 && evento.mouse.y < ALTURA*0.7 + 90 )
                {
                    sair=true;
                }
                else
                {
                    sair=false;
                }
            }

            if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)/**SE CLICAR COM O BOTAO DIREITO ATIVO RECEBE SIM QUE IRA SAIR DO JOGO*/
            {
                if(evento.mouse.x > LARGURA*0.25 && evento.mouse.x < LARGURA*0.25 + al_get_text_width(fonte, sair_texto))
                {
                    if(evento.mouse.y > ALTURA*0.7 && evento.mouse.y < ALTURA*0.7 + 90 )/**90 = TAMANHO DA FONTE*/
                    {
                        ativo=true;/**SAIR DO JOGO*/
                    }
                }
            }

            if(evento.type == ALLEGRO_EVENT_KEY_UP)
            {
                switch(evento.keyboard.keycode)/**SE CLICAR EM ALGUM TECLA */
                {
                    case ALLEGRO_KEY_ESCAPE:/**CASO APARTA ESC APARECER MENSAGEM*/
                    if (al_show_native_message_box(al_get_current_display(), "Logical Challenge",/**MENSAGEM QUE IRA APARECER CASO CLIQUE NO X*/
                        "Fechar Programa", "Deseja encerrar o programa?",
                        NULL, ALLEGRO_MESSAGEBOX_OK_CANCEL))
                    {
                        ativo = true;/**SAIR DO JOGO*/
                    }
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_display_event_source(janela));/**PARAR DE REGISTRAR EVENTOS DA TELA*/
    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());/**PARAR DE  REGISTRAR MOUSE*/
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());/**PARA DE REGISTRAR TECLADO*/

    al_destroy_display(janela);/**APAGAR PONTEIRO  TELA-JANELA*/
    al_destroy_bitmap(fundo_menu);/**APAGAR PONTEIRO IMAGEM DE FUNDO*/
    al_destroy_event_queue(fila_eventos);/**APAGAR PONTEIRO FILA DE EVENTOS*/
    al_destroy_audio_stream(musica);/**APAGAR PONTEIRO MUSICA*/
    al_destroy_sample(click);/**APAGAR PONTEIRO AUDIO PEQUENO*/
    al_destroy_font(fonte);/**APAGAR PONTERIO FONTE*/

    return 0;/** FIM*/
}




