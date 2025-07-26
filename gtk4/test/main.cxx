#include <locale.h>
#include <gtk/gtk.h>
#include "Scintilla.h"
#include "ScintillaWidget.h"

void* app;

int main()
{
	setlocale(LC_ALL, "zh_CN");
	app = gtk_application_new("com.xugtek.scinitlla", G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK([]
		{
			auto win = gtk_application_window_new(GTK_APPLICATION(app));
			auto sci = scintilla_new();
			scintilla_set_id(SCINTILLA(sci), 0);
			scintilla_send_message(SCINTILLA(sci), SCI_STYLESETFONT, STYLE_DEFAULT, (sptr_t)"Consolas");
			scintilla_send_message(SCINTILLA(sci), SCI_STYLESETSIZE, STYLE_DEFAULT, 11);
			scintilla_send_message(SCINTILLA(sci), SCI_SETMARGINWIDTHN, 0, 20);
			scintilla_send_message(SCINTILLA(sci), SCI_SETMARGINTYPEN, 0, SC_MARGIN_NUMBER);
			gtk_window_set_child(GTK_WINDOW(win), GTK_WIDGET(sci));
			gtk_window_present(GTK_WINDOW(win));
		}), nullptr);
	g_application_run(G_APPLICATION(app), 0, nullptr);
}